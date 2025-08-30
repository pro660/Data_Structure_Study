// tiny_search: simple inverted index search engine (supports AND/OR, search logs, snippets)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#ifdef _WIN32
  #define strcasecmp _stricmp
  #define strncasecmp _strnicmp
#endif

#define HASH_SIZE 100003
#define MAX_LINE 4096
#define MAX_TERM_LEN 64
#define MAX_QUERY_LEN 512
#define MAX_SNIPPET 256
#define INITIAL_POST_CAP 4
#define LOG_PATH "search.log"

typedef struct {
    int doc_id;
    int tf;
} Posting;

typedef struct TermNode {
    char *term;
    Posting *arr;
    int size, cap;
    struct TermNode *next;
} TermNode;

typedef struct {
    char *path;
    char preview[MAX_SNIPPET];
} Document;

typedef struct {
    int doc_id;
    int score;
} Hit;

typedef struct {
    Hit *arr;
    int size, cap;
} HitVec;

static TermNode *g_hash[HASH_SIZE];
static Document *g_docs = NULL;
static int g_doc_count = 0;
static int g_log_doc_id = -1;

#ifndef _WIN32
static char* _strdup(const char* s){
    size_t n = strlen(s)+1;
    char* p = (char*)malloc(n);
    if(p) memcpy(p,s,n);
    return p;
}
#endif

static unsigned long hash_str(const char *s){
    unsigned long long h=1469598103934665603ULL;
    while(*s){ h^=(unsigned char)(*s++); h*=1099511628211ULL; }
    return (unsigned long)(h % HASH_SIZE);
}

static void hitvec_init(HitVec *hv){ hv->arr=NULL; hv->size=0; hv->cap=0; }
static void hitvec_free(HitVec *hv){ free(hv->arr); hv->arr=NULL; hv->size=hv->cap=0; }
static void hitvec_push(HitVec *hv, int doc_id, int score){
    if(hv->size==hv->cap){
        hv->cap = hv->cap? hv->cap*2 : 16;
        hv->arr = (Hit*)realloc(hv->arr, sizeof(Hit)*hv->cap);
    }
    hv->arr[hv->size].doc_id = doc_id;
    hv->arr[hv->size].score  = score;
    hv->size++;
}

static int cmp_hit(const void *a, const void *b){
    const Hit *x=(const Hit*)a, *y=(const Hit*)b;
    if(x->score!=y->score) return (y->score - x->score);
    return (x->doc_id - y->doc_id);
}

static TermNode* termnode_new(const char *term){
    TermNode *t = (TermNode*)malloc(sizeof(TermNode));
    t->term = _strdup(term);
    t->arr = (Posting*)malloc(sizeof(Posting)*INITIAL_POST_CAP);
    t->size=0; t->cap=INITIAL_POST_CAP; t->next=NULL;
    return t;
}
static void termnode_free_chain(TermNode *p){
    while(p){ TermNode *n=p->next; free(p->term); free(p->arr); free(p); p=n; }
}

static TermNode* index_get_or_insert(const char *term){
    unsigned long h = hash_str(term);
    for(TermNode *p=g_hash[h]; p; p=p->next)
        if(strcmp(p->term, term)==0) return p;
    TermNode *n = termnode_new(term);
    n->next = g_hash[h];
    g_hash[h]=n;
    return n;
}

static void postings_push(TermNode *t, int doc_id){
    if(t->size>0 && t->arr[t->size-1].doc_id==doc_id){
        t->arr[t->size-1].tf++;
        return;
    }
    if(t->size==t->cap){
        t->cap*=2;
        t->arr=(Posting*)realloc(t->arr, sizeof(Posting)*t->cap);
    }
    t->arr[t->size].doc_id = doc_id;
    t->arr[t->size].tf     = 1;
    t->size++;
}

static TermNode* find_term(const char *term){
    unsigned long h = hash_str(term);
    for(TermNode *p=g_hash[h]; p; p=p->next)
        if(strcmp(p->term, term)==0) return p;
    return NULL;
}

static void add_document(const char *path, int doc_id){
    g_docs[doc_id].path = _strdup(path);
    FILE *fp = fopen(path, "r");
    if(!fp){ snprintf(g_docs[doc_id].preview, MAX_SNIPPET, "(failed to open file: %s)", path); return; }
    if(!fgets(g_docs[doc_id].preview, MAX_SNIPPET, fp)){
        snprintf(g_docs[doc_id].preview, MAX_SNIPPET, "(empty file)");
        fclose(fp); return;
    }
    size_t L = strlen(g_docs[doc_id].preview);
    if(L>0 && (g_docs[doc_id].preview[L-1]=='\n'||g_docs[doc_id].preview[L-1]=='\r'))
        g_docs[doc_id].preview[L-1]='\0';
    fclose(fp);
}

static void index_text_line(const char *line, int doc_id){
    int i=0;
    while(line[i]){
        while(line[i] && !isalnum((unsigned char)line[i])) i++;
        if(!line[i]) break;
        char term[MAX_TERM_LEN]; int k=0;
        while(line[i] && isalnum((unsigned char)line[i]) && k<MAX_TERM_LEN-1)
            term[k++]=(char)tolower((unsigned char)line[i++]);
        term[k]='\0';
        if(k>0){ TermNode *tn = index_get_or_insert(term); postings_push(tn, doc_id); }
    }
}

static void index_file(const char *path, int doc_id){
    FILE *fp = fopen(path, "r");
    if(!fp){ fprintf(stderr,"Warning: failed to open '%s'\n", path); return; }
    char buf[MAX_LINE];
    while(fgets(buf, sizeof(buf), fp)) index_text_line(buf, doc_id);
    fclose(fp);
}

static int tolower_uc(int c){ return tolower((unsigned char)c); }
static const char* strcasestr_local(const char* hay, const char* needle){
    if(!*needle) return hay;
    size_t nl = strlen(needle);
    for(const char* p = hay; *p; ++p){
        size_t i=0;
        while(i<nl && p[i] && tolower_uc(p[i])==tolower_uc(needle[i])) i++;
        if(i==nl) return p;
        if(!p[i]) break;
    }
    return NULL;
}

static void get_snippet_for_doc(int doc_id, const char **qwords, int qn, char *out, size_t cap){
    const char *path = g_docs[doc_id].path;
    FILE *fp = fopen(path, "r");
    if(!fp){ snprintf(out, cap, "%s", g_docs[doc_id].preview); return; }
    char line[MAX_LINE];
    while(fgets(line, sizeof(line), fp)){
        size_t L = strlen(line);
        while(L>0 && (line[L-1]=='\n'||line[L-1]=='\r')) line[--L]='\0';
        for(int i=0;i<qn;i++){
            if(qwords[i] && qwords[i][0]){
                if(strcasestr_local(line, qwords[i])){
                    if(L >= cap-1) snprintf(out, cap, "... %.200s ...", line);
                    else snprintf(out, cap, "%s", line);
                    fclose(fp); return;
                }
            }
        }
    }
    fclose(fp);
    snprintf(out, cap, "%s", g_docs[doc_id].preview);
}

typedef enum { TK_WORD, TK_AND, TK_OR, TK_END } TokType;
typedef struct { TokType type; char word[MAX_TERM_LEN]; } Token;

static int next_token(const char **p, Token *out){
    while(**p && isspace((unsigned char)**p)) (*p)++;
    if(!**p){ out->type=TK_END; return 0; }
    if(strncasecmp(*p,"AND",3)==0 && !isalnum((unsigned char)(*p)[3])){ *p+=3; out->type=TK_AND; return 1; }
    if(strncasecmp(*p,"OR",2)==0  && !isalnum((unsigned char)(*p)[2])) { *p+=2; out->type=TK_OR;  return 1; }
    int k=0; while(**p && !isspace((unsigned char)**p)){ if(k<MAX_TERM_LEN-1) out->word[k++]=(char)tolower((unsigned char)**p); (*p)++; }
    out->word[k]='\0'; out->type=TK_WORD; return 1;
}

static void term_to_hits(const TermNode *tn, HitVec *out){
    hitvec_init(out); if(!tn) return;
    for(int i=0;i<tn->size;i++) hitvec_push(out, tn->arr[i].doc_id, tn->arr[i].tf);
}

static void hits_or (const HitVec *a, const HitVec *b, HitVec *out){
    hitvec_init(out); int i=0,j=0;
    while(i<a->size || j<b->size){
        if(j>=b->size || (i<a->size && a->arr[i].doc_id < b->arr[j].doc_id)){ hitvec_push(out,a->arr[i].doc_id,a->arr[i].score); i++; }
        else if(i>=a->size || (j<b->size && b->arr[j].doc_id < a->arr[i].doc_id)){ hitvec_push(out,b->arr[j].doc_id,b->arr[j].score); j++; }
        else { hitvec_push(out, a->arr[i].doc_id, a->arr[i].score + b->arr[j].score); i++; j++; }
    }
}
static void hits_and(const HitVec *a, const HitVec *b, HitVec *out){
    hitvec_init(out); int i=0,j=0;
    while(i<a->size && j<b->size){
        if(a->arr[i].doc_id==b->arr[j].doc_id){ hitvec_push(out,a->arr[i].doc_id,a->arr[i].score+b->arr[j].score); i++; j++; }
        else if(a->arr[i].doc_id<b->arr[j].doc_id) i++; else j++;
    }
}

static void run_query(const char *qline){
    clock_t t0 = clock();

    const char *p=qline; Token toks[256]; int tn=0;
    while(tn<255){ Token t; if(!next_token(&p,&t)) break; toks[tn++]=t; if(t.type==TK_END) break; }
    if(tn==0 || toks[0].type!=TK_WORD){ printf("(Query must start with a word)\n"); return; }

    const char* qwords[128]; int qn=0; TokType ops[128]; int on=0;
    for(int i=0;i<tn;i++){
        if(toks[i].type==TK_WORD) qwords[qn++]=toks[i].word;
        else if(toks[i].type==TK_AND || toks[i].type==TK_OR) ops[on++]=toks[i].type;
    }
    if(qn==0){ printf("(No words)\n"); return; }

    HitVec groups[128]; int gn=0;
    HitVec cur; { TermNode *t0 = find_term(qwords[0]); term_to_hits(t0, &cur); }
    for(int i=0;i<on;i++){
        TermNode *ti = find_term(qwords[i+1]); HitVec rhs; term_to_hits(ti,&rhs);
        if(ops[i]==TK_AND){ HitVec m; hits_and(&cur,&rhs,&m); hitvec_free(&cur); hitvec_free(&rhs); cur=m; }
        else{ groups[gn++]=cur; cur=rhs; }
    }
    groups[gn++]=cur;

    HitVec acc=groups[0];
    for(int i=1;i<gn;i++){ HitVec m; hits_or(&acc,&groups[i],&m); hitvec_free(&acc); hitvec_free(&groups[i]); acc=m; }

    if(acc.size==0){
        printf("No results.\n");
        long ms=(long)((clock()-t0)*1000/CLOCKS_PER_SEC);
        char ts[32]; { time_t tt=time(NULL); struct tm tmv;
        #ifdef _WIN32
          gmtime_s(&tmv,&tt);
        #else
          gmtime_r(&tt,&tmv);
        #endif
        strftime(ts,sizeof(ts),"%Y-%m-%dT%H:%M:%SZ",&tmv); }
        FILE *fp=fopen(LOG_PATH,"a");
        if(fp){ fprintf(fp,"%s  TAG:SEARCH  QUERY:\"%s\"  HITS:%d  DURATION_MS:%ld\n",ts,qline,0,ms); fclose(fp); }
        if(g_log_doc_id>=0){ char line[1024]; snprintf(line,sizeof(line),"%s  TAG:SEARCH  QUERY:\"%s\"  HITS:%d  DURATION_MS:%ld\n",ts,qline,0,ms); index_text_line(line,g_log_doc_id); }
        return;
    }

    qsort(acc.arr, acc.size, sizeof(Hit), cmp_hit);
    int show = acc.size<10? acc.size:10;
    const char* sn_words[128]; int sn=0; for(int i=0;i<qn && sn<128;i++) sn_words[sn++]=qwords[i];
    for(int i=0;i<show;i++){
        int id=acc.arr[i].doc_id; char snippet[MAX_SNIPPET];
        get_snippet_for_doc(id, sn_words, sn, snippet, sizeof(snippet));
        printf("[%2d] score=%d  doc=%s\n    snippet: %s\n", i+1, acc.arr[i].score, g_docs[id].path, snippet);
    }

    long ms=(long)((clock()-t0)*1000/CLOCKS_PER_SEC);
    char ts[32]; { time_t tt=time(NULL); struct tm tmv;
    #ifdef _WIN32
      gmtime_s(&tmv,&tt);
    #else
      gmtime_r(&tt,&tmv);
    #endif
    strftime(ts,sizeof(ts),"%Y-%m-%dT%H:%M:%SZ",&tmv); }
    FILE *fp=fopen(LOG_PATH,"a");
    if(fp){ fprintf(fp,"%s  TAG:SEARCH  QUERY:\"%s\"  HITS:%d  DURATION_MS:%ld\n",ts,qline,acc.size,ms); fclose(fp); }
    if(g_log_doc_id>=0){ char line[1024]; snprintf(line,sizeof(line),"%s  TAG:SEARCH  QUERY:\"%s\"  HITS:%d  DURATION_MS:%ld\n",ts,qline,acc.size,ms); index_text_line(line,g_log_doc_id); }

    hitvec_free(&acc);
}

int main(int argc, char **argv){
    int input_docs = (argc>=2)? (argc-1) : 0; // 입력 문서 수
    g_doc_count = input_docs + 1; // 전체 문서 수 (로그 포함)
    g_docs = (Document*)calloc(g_doc_count, sizeof(Document)); // 문서 배열 할당(calloc은 malloc + 0 초기화)

    for(int i=1;i<argc;i++){ add_document(argv[i], i-1); index_file(argv[i], i-1); } // 문서 추가 및 인덱싱

    g_log_doc_id = g_doc_count - 1;
    add_document(LOG_PATH, g_log_doc_id);
    index_file(LOG_PATH, g_log_doc_id);

    printf("Indexing complete: %d documents (including log)\n", g_doc_count);
    printf("Example queries: error AND timeout, login OR signup, TAG:SEARCH AND query\nExit: :quit\n");

    char qline[MAX_QUERY_LEN];
    while(1){
        printf("> ");
        if(!fgets(qline, sizeof(qline), stdin)) break;
        if(strncmp(qline,":quit",5)==0) break;
        size_t L=strlen(qline); while(L>0 && (qline[L-1]=='\n'||qline[L-1]=='\r')) qline[--L]='\0';
        if(qline[0]=='\0') continue;
        run_query(qline);
    }

    for(int i=0;i<HASH_SIZE;i++) termnode_free_chain(g_hash[i]);
    for(int i=0;i<g_doc_count;i++) free(g_docs[i].path);
    free(g_docs);
    return 0;
}

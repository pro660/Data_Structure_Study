//
//// 1. 후위식 표기법
//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_STACK_SIZE 100
//typedef enum {
//	lparen, rparen, plus, minus, times,
//	divide, mod, eos, operand
//}precedence;
//char expr[100];
//int stack[MAX_STACK_SIZE];
//int top = -1;
//int isp[] = { 0,19,12,12,13,13,13,0 };
//int icp[] = { 20,19,12,12,13,13,13,0 };
//void push(int item)
//{
//	if (top >= MAX_STACK_SIZE - 1) {
//		printf("stack full\n");
//		exit(1);
//	}
//	stack[++top] = item;
//}
//int pop()
//{
//	if (top == -1)
//	{
//		printf("stack empty.\n");
//		exit(1);
//	}
//	return stack[top--];
//}
//void printToken(precedence token)
//{
//	switch (token)
//	{
//	case plus: printf("+"); break;
//	case minus: printf("-"); break;
//	case times: printf("*"); break;
//	case divide: printf("/"); break;
//	case mod: printf("%%"); break;
//	case lparen: printf("("); break;
//	case rparen: printf(")"); break;
//	}
//}
//precedence getToken(char* symbol, int* n)
//{
//	*symbol = expr[(*n)++];
//	switch (*symbol)
//	{
//	case '(':return lparen;
//	case ')': return rparen;
//	case '+': return plus;
//	case '-': return minus;
//	case '/': return divide;
//	case '*': return times;
//	case '%': return mod;
//	case '\0': return eos;
//	default: return operand;
//	}
//}
//void postfix(void)
//{
//	char symbol;
//	precedence token;
//	int n = 0;
//	top = 0;
//	stack[0] = eos;
//	for (token = getToken(&symbol, &n); token != eos;
//		token = getToken(&symbol, &n))
//	{
//		if (token == operand)
//			printf("%c", symbol);
//		else if (token == rparen)
//		{
//			while (stack[top] != lparen)
//				printToken(pop());
//			pop();
//		}
//		else
//		{
//			while (isp[stack[top]] >= icp[token])
//				printToken(pop());
//			push(token);
//		}
//	}
//	while ((token = pop()) != eos)
//		printToken(token);
//	printf("\n");
//}
//int main(void)
//{
//	printf("수식을 입력하시오:");
//	scanf_s("%s", expr, (unsigned)_countof(expr));
//	printf("후위 표기식: ");
//	postfix();
//}

// 2.여러가지 자리 정수의 수식 계산
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#define MAX_STACK_SIZE 1000
//typedef enum {
//    lparen, rparen, plus, minus, times,
//    divide, mod, eos, operand
//} precedence;
//char expr[100];
//char postfixExpr[300];
//int stack[MAX_STACK_SIZE];
//int top = -1;
//int isp[] = { 0,19,12,12,13,13,13,0 };
//int icp[] = { 20,19,12,12,13,13,13,0 };
//void push(int item)
//{
//    if (top >= MAX_STACK_SIZE - 1)
//    {
//        printf("stack full.\n");
//        exit(1);
//    }
//    stack[++top] = item;
//}
//int pop()
//{
//    if (top == -1)
//    {
//        printf("stack empty.\n");
//        exit(1);
//    }
//    return stack[top--];
//}
//char tokenToChar(precedence token)
//{
//    switch (token)
//    {
//    case plus: return '+';
//    case minus: return '-';
//    case times: return '*';
//    case divide: return '/';
//    case mod: return '%';
//    default: return '?';
//    }
//}
//precedence getToken(char* symbol, int* n)
//{
//    *symbol = expr[(*n)++];
//    switch (*symbol)
//    {
//    case '(': return lparen;
//    case ')': return rparen;
//    case '+': return plus;
//    case '-': return minus;
//    case '/': return divide;
//    case '*': return times;
//    case '%': return mod;
//    case '\0': return eos;
//    default: return operand;
//    }
//}
//void postfix(void)
//{
//    char symbol;
//    precedence token;
//    int n = 0;
//    top = 0;
//    stack[0] = eos;
//    postfixExpr[0] = '\0';
//    while (expr[n] != '\0')
//    {
//        if (isdigit(expr[n]))
//        {
//            int start = n;
//            while (isdigit(expr[n])) n++;
//            strncat_s(postfixExpr, sizeof(postfixExpr), &expr[start], n - start);
//            int len = (int)strlen(postfixExpr);
//            postfixExpr[len] = ' ';
//            postfixExpr[len + 1] = '\0';
//        }
//        else
//        {
//            token = getToken(&symbol, &n);
//            if (token == rparen)
//            {
//                while (stack[top] != lparen)
//                {
//                    int len = (int)strlen(postfixExpr);
//                    postfixExpr[len] = tokenToChar(pop());
//                    postfixExpr[len + 1] = ' ';
//                    postfixExpr[len + 2] = '\0';
//                }
//                pop();
//            }
//            else
//            {
//                while (isp[stack[top]] >= icp[token])
//                {
//                    int len = (int)strlen(postfixExpr);
//                    postfixExpr[len] = tokenToChar(pop());
//                    postfixExpr[len + 1] = ' ';
//                    postfixExpr[len + 2] = '\0';
//                }
//                push(token);
//            }
//        }
//    }
//    while ((token = pop()) != eos)
//    {
//        int len = (int)strlen(postfixExpr);
//        postfixExpr[len] = tokenToChar(token);
//        postfixExpr[len + 1] = ' ';
//        postfixExpr[len + 2] = '\0';
//    }
//    printf("%s\n", postfixExpr);
//}
//int eval(void)
//{
//    int evalStack[MAX_STACK_SIZE] = { 0 };
//    int evalTop = -1;
//    char* ptr = postfixExpr;
//    while (*ptr)
//    {
//        if (isdigit(*ptr))
//        {
//            int num = 0;
//            while (isdigit(*ptr))
//            {
//                num = num * 10 + (*ptr - '0');
//                ptr++;
//            }
//            evalStack[++evalTop] = num;
//        }
//        else if (*ptr == '+' || *ptr == '-' || *ptr == '*' || *ptr == '/' || *ptr == '%')
//        {
//            int op2 = evalStack[evalTop--];
//            int op1 = evalStack[evalTop--];
//            switch (*ptr)
//            {
//            case '+': evalStack[++evalTop] = op1 + op2; break;
//            case '-': evalStack[++evalTop] = op1 - op2; break;
//            case '*': evalStack[++evalTop] = op1 * op2; break;
//            case '/': evalStack[++evalTop] = op1 / op2; break;
//            case '%': evalStack[++evalTop] = op1 % op2; break;
//            }
//        }
//        ptr++;
//    }
//    return evalStack[evalTop];
//}
//int main(void)
//{
//    printf("수식을 입력하세요 (예: (12+34)*5): ");
//    scanf_s("%s", expr, (unsigned)sizeof(expr));
//    printf("후위표기식: ");
//    postfix();
//    printf("계산 결과: %d\n", eval());
//}

//3. 여러가지 자리 정수에 대한 수식의 계산
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STACK_SIZE 1000

typedef enum {
    lparen, rparen, plus, minus, times,
    divide, mod, eos, operand
} precedence;

char expr[100];
char prefixExpr[300];
int stack[MAX_STACK_SIZE];
int top = -1;

int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0 };
int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0 };

void push(int item) {
    if (top >= MAX_STACK_SIZE - 1) {
        printf("stack full.\n");
        exit(1);
    }
    stack[++top] = item;
}

int pop() {
    if (top == -1) {
        printf("stack empty.\n");
        exit(1);
    }
    return stack[top--];
}

char tokenToChar(precedence token) {
    switch (token) {
    case plus: return '+';
    case minus: return '-';
    case times: return '*';
    case divide: return '/';
    case mod: return '%';
    default: return '?';
    }
}

precedence getToken(char* symbol, int* n) {
    *symbol = expr[(*n)++];
    switch (*symbol) {
    case '(': return lparen;
    case ')': return rparen;
    case '+': return plus;
    case '-': return minus;
    case '/': return divide;
    case '*': return times;
    case '%': return mod;
    case '\0': return eos;
    default: return operand;
    }
}

// Helper to reverse a string
void reverseStr(char* str) {
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        char temp = str[i];
        str[i++] = str[j];
        str[j--] = temp;
    }
}

void prefix(void) {
    char reversedExpr[100];
    int len = strlen(expr);

    // 1. Reverse input expression & swap brackets
    for (int i = 0; i < len; ++i) {
        char ch = expr[len - i - 1];
        if (ch == '(') reversedExpr[i] = ')';
        else if (ch == ')') reversedExpr[i] = '(';
        else reversedExpr[i] = ch;
    }
    reversedExpr[len] = '\0';

    // Use postfix algorithm on reversed expression
    char symbol;
    precedence token;
    int n = 0;
    top = 0;
    stack[0] = eos;
    prefixExpr[0] = '\0';

    while (reversedExpr[n] != '\0') {
        if (isdigit(reversedExpr[n])) {
            int start = n;
            while (isdigit(reversedExpr[n])) n++;
            strncat(prefixExpr, &reversedExpr[start], n - start);
            strcat(prefixExpr, " ");
        }
        else {
            token = getToken(&symbol, &n);
            if (token == rparen) {
                while (stack[top] != lparen) {
                    char op = tokenToChar(pop());
                    int len = strlen(prefixExpr);
                    prefixExpr[len] = op;
                    prefixExpr[len + 1] = ' ';
                    prefixExpr[len + 2] = '\0';
                }
                pop();
            }
            else {
                while (isp[stack[top]] >= icp[token]) {
                    char op = tokenToChar(pop());
                    int len = strlen(prefixExpr);
                    prefixExpr[len] = op;
                    prefixExpr[len + 1] = ' ';
                    prefixExpr[len + 2] = '\0';
                }
                push(token);
            }
        }
    }

    while ((token = pop()) != eos) {
        int len = strlen(prefixExpr);
        prefixExpr[len] = tokenToChar(token);
        prefixExpr[len + 1] = ' ';
        prefixExpr[len + 2] = '\0';
    }

    // Reverse result to get proper prefix
    reverseStr(prefixExpr);
    printf("%s\n", prefixExpr);
}

// Evaluate prefix expression
int eval(void) {
    int evalStack[MAX_STACK_SIZE];
    int evalTop = -1;

    // Reverse the expression for left-to-right scan
    char reversed[300];
    strcpy(reversed, prefixExpr);
    reverseStr(reversed);

    char* ptr = reversed;
    while (*ptr) {
        if (isdigit(*ptr)) {
            int num = 0;
            while (isdigit(*ptr)) {
                num = num * 10 + (*ptr - '0');
                ptr++;
            }
            evalStack[++evalTop] = num;
        }
        else if (*ptr == '+' || *ptr == '-' || *ptr == '*' || *ptr == '/' || *ptr == '%') {
            int op1 = evalStack[evalTop--];
            int op2 = evalStack[evalTop--];
            switch (*ptr) {
            case '+': evalStack[++evalTop] = op1 + op2; break;
            case '-': evalStack[++evalTop] = op1 - op2; break;
            case '*': evalStack[++evalTop] = op1 * op2; break;
            case '/':
                if (op2 == 0) {
                    printf("0으로 나눌 수 없습니다.\n");
                    exit(1);
                }
                evalStack[++evalTop] = op1 / op2; break;
            case '%': evalStack[++evalTop] = op1 % op2; break;
            }
        }
        ptr++;
    }
    return evalStack[evalTop];
}

int main(void) {
    printf("수식을 입력하세요 (예: (12+34)*5): ");
    scanf("%99s", expr);
    printf("전위표기식: ");
    prefix();
    printf("계산 결과: %d\n", eval());
    return 0;
}

// 4.미로 찾기
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX_STACK_SIZE 1000
//#define MAX_ROW 12
//#define MAX_COL 15
//#define EXIT_ROW 11
//#define EXIT_COL 14
//#define TRUE 1
//#define FALSE 0
//
//// 방향과 위치 구조체
//typedef struct {
//    short int row;
//    short int col;
//    short int dir;
//} element;
//
//typedef struct {
//    int vert;
//    int horiz;
//} offset;
//
//// 스택 및 미로 상태
//element stack[MAX_STACK_SIZE];
//int top = -1;
//int mark[MAX_ROW][MAX_COL] = { 0 };  // 방문 체크
//
//// 미로 (0: 통로, 1: 벽)
//int maze[MAX_ROW][MAX_COL] = {
//    {0,1,0,0,0,1,1,0,0,0,1,1,1,1,1},
//    {1,0,0,0,1,1,0,1,1,1,0,0,1,1,1},
//    {0,1,1,0,0,0,0,1,1,1,1,0,0,1,1},
//    {1,1,0,1,1,1,1,0,1,1,0,1,1,0,0},
//    {1,1,0,1,0,0,1,0,1,1,1,1,1,1,1},
//    {0,0,1,1,0,1,1,1,0,1,0,0,1,0,1},
//    {0,0,1,1,0,1,1,1,0,1,0,0,1,0,1},
//    {0,1,1,1,1,0,0,1,1,1,1,1,1,1,1},
//    {0,0,1,1,0,1,1,0,1,1,1,1,1,0,1},
//    {1,1,0,0,0,1,1,0,1,1,0,0,0,0,0},
//    {0,0,1,1,1,1,1,0,0,0,1,1,1,1,0},
//    {0,1,0,0,1,1,1,1,1,0,1,1,1,1,0}
//};
//
//// 방향 벡터: 북, 북동, 동, 남동, 남, 남서, 서, 북서
//offset move[8] = {
//    {-1, 0}, {-1, 1}, {0, 1}, {1, 1},
//    {1, 0}, {1, -1}, {0, -1}, {-1, -1}
//};
//
//// 스택 push
//void push(element item) {
//    if (top >= MAX_STACK_SIZE - 1) {
//        printf("스택이 가득 찼습니다.\n");
//        exit(1);
//    }
//    stack[++top] = item;
//}
//
//// 스택 pop
//element pop() {
//    if (top < 0) {
//        printf("스택이 비었습니다.\n");
//        exit(1);
//    }
//    return stack[top--];
//}
//
//// 미로 경로 찾기 함수
//void path(void) {
//    int i, row, col, nextRow, nextCol, dir, found = FALSE;
//    element position;
//
//    // 시작점 설정
//    mark[1][1] = 1;
//    top = 0;
//    stack[0].row = 1;
//    stack[0].col = 1;
//    stack[0].dir = 0;
//
//    while (top > -1 && !found) {
//        position = pop();
//        row = position.row;
//        col = position.col;
//        dir = position.dir;
//
//        while (dir < 8 && !found) {
//            nextRow = row + move[dir].vert;
//            nextCol = col + move[dir].horiz;
//
//            // 범위 벗어남 방지
//            if (nextRow < 0 || nextRow >= MAX_ROW || nextCol < 0 || nextCol >= MAX_COL) {
//                dir++;
//                continue;
//            }
//
//            if (nextRow == EXIT_ROW && nextCol == EXIT_COL) {
//                // 도착!
//                found = TRUE;
//                // 현재 경로를 스택에 넣기
//                position.row = row;
//                position.col = col;
//                position.dir = dir;
//                push(position);
//            }
//            else if (!maze[nextRow][nextCol] && !mark[nextRow][nextCol]) {
//                // 방문 안 한 통로
//                mark[nextRow][nextCol] = 1;
//
//                // 현재 위치를 push 후 다음 위치로 이동
//                position.row = row;
//                position.col = col;
//                position.dir = dir + 1; // 다음 시도할 방향 저장
//                push(position);
//
//                row = nextRow;
//                col = nextCol;
//                dir = 0; // 새로운 위치에서 다시 0부터 방향 시도
//            }
//            else {
//                dir++;
//            }
//        }
//    }
//
//    // 경로 출력
//    if (found) {
//        printf("The path is:\n");
//        printf("row col\n");
//
//        for (i = 0; i <= top; i++)
//            printf("%3d%5d\n", stack[i].row, stack[i].col);
//
//        // 마지막 경로 위치
//        printf("%3d%5d\n", EXIT_ROW, EXIT_COL);
//    }
//    else {
//        printf("The maze does not have a path.\n");
//    }
//}
//
//// 메인 함수
//int main(void) {
//    path();
//    return 0;
//}

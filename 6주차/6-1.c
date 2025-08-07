// 탐욕 알고리즘을 이용해서 최소 신장 트리 구성하기
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
#define MAX_EDGES 100
typedef struct {
    int u, v;
    int weight;
} Edge;
int parent[MAX_VERTICES];
int find(int x) 
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}
void unionSet(int x, int y) 
{
    x = find(x);
    y = find(y);
    if (x != y)
        parent[y] = x;
}
int compare(const void* a, const void* b)
{
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;
    return e1->weight - e2->weight;
}
int main() 
{
    int vertices = 6;  
    int edgesCount = 9;  
    Edge edges[MAX_EDGES] = 
    {
        {0, 1, 4}, {0, 2, 4}, 
        {1, 2, 2}, {1, 0, 4},
        {2, 0, 4}, {2, 1, 2}, 
        {2, 3, 3}, {2, 5, 2},
        {3, 4, 3}
    };
    for (int i = 0; i < vertices; i++)
        parent[i] = i;
    qsort(edges, edgesCount, sizeof(Edge), compare);
    int mstWeight = 0;
    printf("선택된 간선들 (MST):\n");
    for (int i = 0, count = 0; count < vertices - 1 && i < edgesCount; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;
        if (find(u) != find(v)) {
            unionSet(u, v);
            printf("(%d, %d) 가중치: %d\n", u, v, w);
            mstWeight += w;
            count++;
        }
    }
    printf("MST 총 가중치: %d\n", mstWeight);
}

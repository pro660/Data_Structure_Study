// 동적 계산법을 이용하여 최단경로 알고리즘 사용해보기
#include <stdio.h>
#define INF 1000000000
int main(void) 
{
    int n = 4; 
    int dist[4][4] = 
    {
        {0,     5,   INF, 8},
        {7,     0,   9,   INF},
        {2,     INF, 0,   4},
        {INF,   INF, 3,   0}
    };
    for (int k = 0; k < n; k++)
    {         
        for (int i = 0; i < n; i++)
        {    
            for (int j = 0; j < n; j++)
            { 
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printf("모든 정점 쌍의 최단 경로 길이:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", dist[i][j]);
        }
        printf("\n");
    }
}
/* 백 트랙킹 */
/*
https://www.google.com/search?q=%EB%B0%B1%ED%8A%B8%EB%9E%98%ED%82%B9+c%EC%96%B8%EC%96%B4&sca_esv=4978fba7b0bac1f0&sxsrf=AE3TifNNMoqcajY-gNeulY5IdtjB6Ku6Yw%3A1755065175338&ei=VyucaPazFM6Mvr0PjMLRwA8&ved=0ahUKEwi2u9Wij4ePAxVOhq8BHQxhFPgQ4dUDCBA&uact=5&oq=%EB%B0%B1%ED%8A%B8%EB%9E%98%ED%82%B9+c%EC%96%B8%EC%96%B4&gs_lp=Egxnd3Mtd2l6LXNlcnAiFOuwse2KuOuemO2CuSBj7Ja47Ja0MgUQABiABDIGEAAYCBgeMgUQABjvBUiqGlDsAljNGHACeAGQAQCYAdMBoAGeDKoBBTAuNC40uAEDyAEA-AEBmAIHoALTCMICChAAGLADGNYEGEfCAgoQIxiABBgnGIoFwgIKEAAYgAQYFBiHAsICChAAGIAEGEMYigXCAggQABiABBiiBMICBBAAGB6YAwCIBgGQBgqSBwUyLjEuNKAH1ReyBwUwLjEuNLgHrgjCBwcyLTMuMy4xyAdP&sclient=gws-wiz-serp
https://code-lab1.tistory.com/442
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n; // n x n 보드판의 크기 n 
int* col; // 각 행별로 퀸의 열(column) 위치 

void printQueens()
{
    int i;
    printf(" ");
    for (i = 1; i <= n; i++)
        printf("(%d, %d)\n ", i, col[i]);
    exit(1);
}

int promising(int i) // 유망한지 체크 
{
    int k = 1;
    while (k < i)
    {
        if (col[i] == col[k] || abs(col[i] - col[k]) == abs(i - k)) // 상하좌우, 대각선 상에 있는 지 
            return 0;
        k++;
    }
    return 1;
}

void queens(int i)
{
    int j;

    if (promising(i)) // 유망하다면  
    {
        if (i == n) // 마지막 행까지 선택이 끝났다면 
        {
            printQueens(); // 퀸의 위치 출력 
            return;
        }
        else // 아직 끝나지 않았다면 
        {
            for (j = 1; j <= n; j++) // 모든 열 탐색 
            {
                col[i + 1] = j;
                queens(i + 1);
            }
        }
    }

}

int main()
{
    printf("Input N: ");
    scanf_s("%d", &n);
    col = (int*)malloc(sizeof(int) * (n + 1));
    queens(0);
    printf("No solution"); // 해결법이 없을 경우 

    return 0;
}
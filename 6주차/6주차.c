/*
다음 주제에 대해 알고리즘 교재나 인터넷 자료를 찾아 개념 정리
하고 각 주제별로 예제 프로그램 1개 이상 작성해보기
- 탐욕 알고리즘
- 백 트랙킹
*/

/* 탐욕 알고리즘 */
/*
https://www.google.com/search?q=%ED%83%90%EC%9A%95+%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98+c%EC%96%B8%EC%96%B4&sca_esv=d8b04fc949d05faa&sxsrf=AE3TifOe-p87vJe7OqpPxnyk7XOFYaUkxQ%3A1755050204277&ei=3PCbaJXXEIabvr0P3-um8Q0&ved=0ahUKEwiVtfS_14aPAxWGja8BHd-1Kd4Q4dUDCBA&uact=5&oq=%ED%83%90%EC%9A%95+%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98+c%EC%96%B8%EC%96%B4&gs_lp=Egxnd3Mtd2l6LXNlcnAiG-2DkOyalSDslYzqs6DrpqzsppggY-yWuOyWtDIIEAAYgAQYogQyBRAAGO8FMgUQABjvBTIFEAAY7wUyBRAAGO8FSKIaUJ0DWOwYcAV4AJABAJgByQGgAYAOqgEGMC4xMC4xuAEDyAEA-AEBmAIMoAKxCsICChAAGLADGNYEGEfCAgcQIRigARgKwgIKECMYgAQYJxiKBcICBRAAGIAEwgIEEAAYHsICBRAhGKABmAMAiAYBkAYKkgcFNS42LjGgB6IksgcFMC42LjG4B_AJwgcFMi02LjbIB24&sclient=gws-wiz-serp
https://nolzaheo.tistory.com/13#:~:text=%EB%8F%99%EC%A0%84%EC%9D%98%20%EA%B0%9C%EC%88%98%EA%B0%80%20%EC%B5%9C%EC%86%8C%EA%B0%80%20%EB%90%98%EB%8F%84%EB%A1%9D%20%EA%B1%B0%EC%8A%A4%EB%A6%84%20%EB%8F%88%EC%9D%84%20%EC%A3%BC%EB%8A%94,%EC%9C%84%EC%97%90%EC%84%9C%20%EC%82%B4%ED%8E%B4%EB%B4%A4%EB%8D%98%203%EA%B0%80%EC%A7%80%20%EA%B5%AC%EC%84%B1%EC%9C%BC%EB%A1%9C%20%EC%A0%95%EB%A6%AC%ED%95%98%EB%A9%B4%20%EB%8B%A4%EC%9D%8C%EA%B3%BC%20%EA%B0%99%EB%8B%A4.
*/

//#include <stdio.h>
//int main()
//{
//    int amount, coin_types[] = { 500, 100, 50, 10 };
//    int num_coins = 0;
//    int num_coin_types = sizeof(coin_types) / sizeof(coin_types[0]);
//
//    printf("거스름돈: ");
//    scanf_s("%d", &amount);
//
//    for (int i = 0; i < num_coin_types; i++)
//    {
//        while (amount >= coin_types[i])
//        {
//            amount -= coin_types[i];
//            num_coins++;
//        }
//    }
//
//    printf("최소 동전 개수: %d\n", num_coins);
//    return 0;
//}

/* 백 트랙킹 */
/*
https://www.google.com/search?q=%EB%B0%B1%ED%8A%B8%EB%9E%98%ED%82%B9+c%EC%96%B8%EC%96%B4&sca_esv=4978fba7b0bac1f0&sxsrf=AE3TifNNMoqcajY-gNeulY5IdtjB6Ku6Yw%3A1755065175338&ei=VyucaPazFM6Mvr0PjMLRwA8&ved=0ahUKEwi2u9Wij4ePAxVOhq8BHQxhFPgQ4dUDCBA&uact=5&oq=%EB%B0%B1%ED%8A%B8%EB%9E%98%ED%82%B9+c%EC%96%B8%EC%96%B4&gs_lp=Egxnd3Mtd2l6LXNlcnAiFOuwse2KuOuemO2CuSBj7Ja47Ja0MgUQABiABDIGEAAYCBgeMgUQABjvBUiqGlDsAljNGHACeAGQAQCYAdMBoAGeDKoBBTAuNC40uAEDyAEA-AEBmAIHoALTCMICChAAGLADGNYEGEfCAgoQIxiABBgnGIoFwgIKEAAYgAQYFBiHAsICChAAGIAEGEMYigXCAggQABiABBiiBMICBBAAGB6YAwCIBgGQBgqSBwUyLjEuNKAH1ReyBwUwLjEuNLgHrgjCBwcyLTMuMy4xyAdP&sclient=gws-wiz-serp
https://code-lab1.tistory.com/442
*/

//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//
//int n; // n x n 보드판의 크기 n 
//int* col; // 각 행별로 퀸의 열(column) 위치 
//
//void printQueens()
//{
//    int i;
//    printf(" ");
//    for (i = 1; i <= n; i++)
//        printf("(%d, %d)\n ", i, col[i]);
//    exit(1);
//}
//
//int promising(int i) // 유망한지 체크 
//{
//    int k = 1;
//    while (k < i)
//    {
//        if (col[i] == col[k] || abs(col[i] - col[k]) == abs(i - k)) // 상하좌우, 대각선 상에 있는 지 
//            return 0;
//        k++;
//    }
//    return 1;
//}
//
//void queens(int i)
//{
//    int j;
//
//    if (promising(i)) // 유망하다면  
//    {
//        if (i == n) // 마지막 행까지 선택이 끝났다면 
//        {
//            printQueens(); // 퀸의 위치 출력 
//            return;
//        }
//        else // 아직 끝나지 않았다면 
//        {
//            for (j = 1; j <= n; j++) // 모든 열 탐색 
//            {
//                col[i + 1] = j;
//                queens(i + 1);
//            }
//        }
//    }
//
//}
//
//int main()
//{
//    printf("Input N: ");
//    scanf_s("%d", &n);
//    col = (int*)malloc(sizeof(int) * (n + 1));
//    queens(0);
//    printf("No solution"); // 해결법이 없을 경우 
//
//    return 0;
//}

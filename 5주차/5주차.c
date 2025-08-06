/*
다음 주제에 대해 알고리즘 교재나 인터넷 자료를 찾아 개념 정리하고 각 주제별로 예제 프로그램 1개 이상 작성해보기
- 분할 정복
- 동적 계획법
*/

/* 분할 정복 */
/*
https://best-coding.tistory.com/88
https://www.google.com/search?q=%EB%B6%84%ED%95%A0%EC%A0%95%EB%B3%B5+%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98+c&sca_esv=d5e847b1dc31b2cb&sxsrf=AE3TifNJ1qAyj0IZQVK8MEccEy2Cig1cAg%3A1754410926240&ei=ri-SaK65Dsyk2roP7Mic4Qo&ved=0ahUKEwiuyLGAivSOAxVMklYBHWwkJ6wQ4dUDCBA&uact=5&oq=%EB%B6%84%ED%95%A0%EC%A0%95%EB%B3%B5+%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98+c&gs_lp=Egxnd3Mtd2l6LXNlcnAiG-u2hO2VoOygleuztSDslYzqs6DrpqzsppggYzIKECMYgAQYJxiKBTIIEAAYogQYiQUyBRAAGO8FMgUQABjvBTIFEAAY7wVIiQhQ7gRYngZwAXgAkAEAmAH1AaAB6ASqAQUwLjIuMbgBA8gBAPgBAZgCAqACzAHCAggQABiABBiwA8ICCxAAGIAEGLADGKIEwgILEAAYsAMYogQYiQXCAggQABiwAxjvBZgDAIgGAZAGBZIHAzEuMaAH-AyyBwMwLjG4B8UBwgcFMi0xLjHIBxI&sclient=gws-wiz-serp
*/

//#include <stdio.h>
//
//void merge(int arr[], int l, int m, int r)
//{
//    int i, j, k;
//    int n1 = m - l + 1;
//    int n2 = r - m;
//
//    int L[n1], R[n2];
//
//    for (i = 0; i < n1; i++)
//        L[i] = arr[l + i];
//    for (j = 0; j < n2; j++)
//        R[j] = arr[m + 1 + j];
//
//    i = 0;
//    j = 0;
//    k = l;
//    while (i < n1 && j < n2) {
//        if (L[i] <= R[j]) {
//            arr[k] = L[i];
//            i++;
//        }
//        else {
//            arr[k] = R[j];
//            j++;
//        }
//        k++;
//    }
//
//    while (i < n1) {
//        arr[k] = L[i];
//        i++;
//        k++;
//    }
//
//    while (j < n2) {
//        arr[k] = R[j];
//        j++;
//        k++;
//    }
//}
//
//void mergeSort(int arr[], int l, int r)
//{
//    if (l < r) {
//        int m = l + (r - l) / 2;
//
//        mergeSort(arr, l, m);
//        mergeSort(arr, m + 1, r);
//
//        merge(arr, l, m, r);
//    }
//}
//
//int main()
//{
//    int arr[] = { 12, 11, 13, 5, 6, 7 };
//    int arr_size = sizeof(arr) / sizeof(arr[0]);
//
//    printf("정렬 전 배열: \n");
//    for (int i = 0; i < arr_size; i++)
//        printf("%d ", arr[i]);
//    printf("\n");
//
//    mergeSort(arr, 0, arr_size - 1);
//
//    printf("정렬 후 배열: \n");
//    for (int i = 0; i < arr_size; i++)
//        printf("%d ", arr[i]);
//    printf("\n");
//    return 0;
//}

//#include <stdio.h>
//#define MAX_SIZE 100
//
//void merge(int arr[], int l, int m, int r)
//{
//    int i, j, k;
//    int n1 = m - l + 1;
//    int n2 = r - m;
//
//    int L[MAX_SIZE], R[MAX_SIZE];
//
//    for (i = 0; i < n1; i++)
//        L[i] = arr[l + i];
//    for (j = 0; j < n2; j++)
//        R[j] = arr[m + 1 + j];
//
//    i = 0;
//    j = 0;
//    k = l;
//    while (i < n1 && j < n2)
//    {
//        if (L[i] <= R[j])
//        {
//            arr[k] = L[i];
//            i++;
//        }
//        else
//        {
//            arr[k] = R[j];
//            j++;
//        }
//        k++;
//    }
//
//    while (i < n1)
//    {
//        arr[k] = L[i];
//        i++;
//        k++;
//    }
//
//    while (j < n2)
//    {
//        arr[k] = R[j];
//        j++;
//        k++;
//    }
//}
//
//void mergeSort(int arr[], int l, int r)
//{   
//    if (l < r)
//    {
//        int m = l + (r - l) / 2;
//
//        mergeSort(arr, l, m);
//        mergeSort(arr, m + 1, r);
//
//        merge(arr, l, m, r);
//    }
//}
//
//int main()
//{
//    int arr[] = { 12, 11, 13, 5, 6, 7 };
//    int arr_size = sizeof(arr) / sizeof(arr[0]);
//
//    printf("정렬 전 배열: \n");
//    for (int i = 0; i < arr_size; i++)
//        printf("%d ", arr[i]);
//    printf("\n");
//
//    mergeSort(arr, 0, arr_size - 1);
//
//    printf("정렬 후 배열: \n");
//    for (int i = 0; i < arr_size; i++)
//        printf("%d ", arr[i]);
//    printf("\n");
//    return 0;
//}

/* 동적 계획법 */
/*
https://www.youtube.com/watch?v=T4WUpYsCqSU&t=1s
https://8iggy.tistory.com/143#:~:text=%EB%8F%99%EC%A0%81%20%EA%B3%84%ED%9A%8D%EB%B2%95%20%EA%B5%AC%ED%98%84%EC%97%90%EB%8A%94%202%20%EA%B0%80%EC%A7%80%EA%B0%80%20%EC%9E%88%EB%8A%94%EB%8D%B0%20%EB%8C%80%ED%91%9C%EC%A0%81%20DP%20%EB%AC%B8%EC%A0%9C%EC%9D%B8%20%ED%94%BC%EB%B3%B4%EB%82%98%EC%B9%98%20%EC%88%98%EC%97%B4%EB%A1%9C%20%EC%98%88%EC%8B%9C%EB%A5%BC%20%EB%93%A4%EC%96%B4%EB%B3%B4%EC%9E%90.
https://www.google.com/search?q=%EB%8F%99%EC%A0%81+%EA%B3%84%ED%9A%8D%EB%B2%95+%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98+c%EC%96%B8%EC%96%B4&sca_esv=7d0b40d4ccf1baac&hl=ko&sxsrf=AE3TifOWcOd1PU8fEHDnZki6kwA-TkuogQ%3A1754441237831&source=hp&ei=FaaSaPD0MMmf4-EPgJSu4A8&iflsig=AOw8s4IAAAAAaJK0JX_kztjfG9IXOukAEcFwm3c6XeJg&oq=&gs_lp=Egdnd3Mtd2l6IgAqAggAMgcQIxgnGOoCMgcQIxgnGOoCMgcQIxgnGOoCMgoQIxjwBRgnGOoCMgcQIxgnGOoCMgcQIxgnGOoCMgcQIxgnGOoCMgcQIxgnGOoCMgcQIxgnGOoCMgcQIxgnGOoCSPcFUABYAHABeACQAQCYAQCgAQCqAQC4AQHIAQCYAgGgAg2oAgqYAw3xBcHEGvoIW3RQkgcBMaAHALIHALgHAMIHAzMtMcgHCg&sclient=gws-wiz
*/

//#include <stdio.h>
//
//// 재귀 함수를 이용한 피보나치 수열 (메모이제이션 미적용)
//int fibonacci_recursive(int n)
//{
//    if (n <= 1) {
//        return n;
//    }
//    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
//}
//
//// 동적 계획법 (메모이제이션)을 이용한 피보나치 수열
//int fibonacci_dp(int n)
//{
//    int dp[n + 1];
//    dp[0] = 0;
//    dp[1] = 1;
//    for (int i = 2; i <= n; i++) {
//        dp[i] = dp[i - 1] + dp[i - 2];
//    }
//    return dp[n];
//}
//
//int main()
//{
//    int num = 10;
//    printf("피보나치 수열 (%d): %d (재귀)\n", num, fibonacci_recursive(num));
//    printf("피보나치 수열 (%d): %d (동적 계획법)\n", num, fibonacci_dp(num));
//    return 0;
//}

//#include <stdio.h>
//#define MAX_SIZE 100
//
//// 재귀 함수를 이용한 피보나치 수열 (메모이제이션 미적용)
//int fibonacci_recursive(int n)
//{
//    if (n <= 1) {
//        return n;
//    }
//    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
//}
//
//// 동적 계획법 (메모이제이션)을 이용한 피보나치 수열
//int fibonacci_dp(int n)
//{
//    int dp[MAX_SIZE];  // 충분히 큰 정적 배열 선언
//    dp[0] = 0;
//    dp[1] = 1;
//    for (int i = 2; i <= n; i++) {
//        dp[i] = dp[i - 1] + dp[i - 2];
//    }
//    return dp[n];
//}
//
//int main()
//{
//    int num = 10;
//    printf("피보나치 수열 (%d): %d (재귀)\n", num, fibonacci_recursive(num));
//    printf("피보나치 수열 (%d): %d (동적 계획법)\n", num, fibonacci_dp(num));
//    return 0;
//}

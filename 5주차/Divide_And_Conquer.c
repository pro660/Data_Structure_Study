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

#include <stdio.h>
#define MAX_SIZE 100

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[MAX_SIZE], R[MAX_SIZE];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{   
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("정렬 전 배열: \n");
    for (int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    mergeSort(arr, 0, arr_size - 1);

    printf("정렬 후 배열: \n");
    for (int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

/* 탐욕 알고리즘 */
/*
https://www.google.com/search?q=%ED%83%90%EC%9A%95+%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98+c%EC%96%B8%EC%96%B4&sca_esv=d8b04fc949d05faa&sxsrf=AE3TifOe-p87vJe7OqpPxnyk7XOFYaUkxQ%3A1755050204277&ei=3PCbaJXXEIabvr0P3-um8Q0&ved=0ahUKEwiVtfS_14aPAxWGja8BHd-1Kd4Q4dUDCBA&uact=5&oq=%ED%83%90%EC%9A%95+%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98+c%EC%96%B8%EC%96%B4&gs_lp=Egxnd3Mtd2l6LXNlcnAiG-2DkOyalSDslYzqs6DrpqzsppggY-yWuOyWtDIIEAAYgAQYogQyBRAAGO8FMgUQABjvBTIFEAAY7wUyBRAAGO8FSKIaUJ0DWOwYcAV4AJABAJgByQGgAYAOqgEGMC4xMC4xuAEDyAEA-AEBmAIMoAKxCsICChAAGLADGNYEGEfCAgcQIRigARgKwgIKECMYgAQYJxiKBcICBRAAGIAEwgIEEAAYHsICBRAhGKABmAMAiAYBkAYKkgcFNS42LjGgB6IksgcFMC42LjG4B_AJwgcFMi02LjbIB24&sclient=gws-wiz-serp
https://nolzaheo.tistory.com/13#:~:text=%EB%8F%99%EC%A0%84%EC%9D%98%20%EA%B0%9C%EC%88%98%EA%B0%80%20%EC%B5%9C%EC%86%8C%EA%B0%80%20%EB%90%98%EB%8F%84%EB%A1%9D%20%EA%B1%B0%EC%8A%A4%EB%A6%84%20%EB%8F%88%EC%9D%84%20%EC%A3%BC%EB%8A%94,%EC%9C%84%EC%97%90%EC%84%9C%20%EC%82%B4%ED%8E%B4%EB%B4%A4%EB%8D%98%203%EA%B0%80%EC%A7%80%20%EA%B5%AC%EC%84%B1%EC%9C%BC%EB%A1%9C%20%EC%A0%95%EB%A6%AC%ED%95%98%EB%A9%B4%20%EB%8B%A4%EC%9D%8C%EA%B3%BC%20%EA%B0%99%EB%8B%A4.
*/

#include <stdio.h>
int main()
{
    int amount, coin_types[] = { 500, 100, 50, 10 };
    int num_coins = 0;
    int num_coin_types = sizeof(coin_types) / sizeof(coin_types[0]);

    printf("거스름돈: ");
    scanf_s("%d", &amount);

    for (int i = 0; i < num_coin_types; i++)
    {
        while (amount >= coin_types[i])
        {
            amount -= coin_types[i];
            num_coins++;
        }
    }

    printf("최소 동전 개수: %d\n", num_coins);
    return 0;
}
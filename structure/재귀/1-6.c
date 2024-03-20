#include <stdio.h>
#pragma warning(disable:4996)

void gcd(int n, int m)
{
    if(m == 0){
        printf("%d", n);
    }
    else{
        gcd(m, n%m);
    }
}

int main()
{
    int a, b = 0;
    scanf("%d %d", &a, &b);
    gcd(a, b);
    return 0;
}
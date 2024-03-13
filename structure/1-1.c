#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int modulo(int a, int b)
{
    while(1){
        if(a < b) break;
        a = a - b;
    }
    printf("%d", a);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    modulo(n, m);
    return 0;
}
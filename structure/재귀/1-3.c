#include <stdio.h>
#pragma:warning(disable:4996)

void print(int N);

int main()
{
    int N;
    scanf("%d", &N);
    print(N);
    return 0;
}

void print(int N)
{
    int a = 0;
    if(N < 10){
        printf("%d\n", N);
    }
    else{
        a = N % 10;
        printf("%d\n", a);
        N = N / 10;
        print(N);
    }
}
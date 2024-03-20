#include <stdio.h>
#pragma warning(disable:4996)

void print(int n)
{
    int a = 0;
    if(n < 10){
        printf("%d\n", n);
    }
    else{
        a = n % 10;
        n = n / 10;
        print(n);
        printf("%d\n", a);
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    print(N);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
int product(int N)
{
    int sum = 0;
    if(N == 1){
        sum = N;
        return sum;
    }
    else{
        sum = N;
        sum += product(N-1);
        return sum;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", product(n));
    return 0;
}
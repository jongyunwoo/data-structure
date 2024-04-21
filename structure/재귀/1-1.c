#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int product(int N) //합 구하기
{
    int sum = 0;
    if(N == 1){ // N이 1이면 그대로 반환
        sum = N;
        return sum;
    }
    else{
        sum = N;
        sum += product(N-1); //1씩 줄여가면서 sum에다 합치기
        return sum; // 합 반환 
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", product(n));
    return 0;
}
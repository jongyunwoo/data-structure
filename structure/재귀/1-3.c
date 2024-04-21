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
        printf("%d\n", N); //N이 일의자리수라면 바로 출력
    }
    else{
        a = N % 10; //가장 낮은 자리수
        printf("%d\n", a); // 낮은 자리수부터 출력하는 프로그램이므로 곧바로 출력
        N = N / 10;
        print(N); // 재귀함수
    }
}
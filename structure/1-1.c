#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int modulo(int a, int b) // 덧셈과 뺄셈만으로 a % b 구하기
{
    while(1){
        if(a < b) break; // a가 b보다 작으면 멈춘다
        a = a - b; // 나머지 구하기이므로 a에서 b를 계속 뺀다
    }
    printf("%d", a); // a%b
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    modulo(n, m);
    return 0;
}
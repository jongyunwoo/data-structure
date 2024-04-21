// 양의 정수를 입력 받아, 각 자리의 수를 높은 자릿수부터 차례로 출력하는 프로그램
#include <stdio.h>
#pragma warning(disable:4996)

void print(int n) //입력받은 정수
{
    int a = 0;
    if(n < 10){ //n이 1의자리수이면 그대로 출력
        printf("%d\n", n);
    }
    else{
        a = n % 10; //재귀함수로 인해 가장 높은 자리수부터 a에 저장
        n = n / 10; // 다음 계산을 위해 n/10
        print(n); // 재귀
        printf("%d\n", a); //가장 높은 자리수부터 출력 
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    print(N);
    return 0;
}
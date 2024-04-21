//최대공약수(gcd) 구하기
#include <stdio.h>
#pragma warning(disable:4996)

void gcd(int n, int m)//유클리드 호제법
{
    //한 쪽의 수가 0이 되었을 때 다른 수가 최대 공약수
    if(m == 0){
        printf("%d", n); // m이 0일 때 최대공약수 n
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
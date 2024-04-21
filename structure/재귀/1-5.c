// 하노이탑 프로그램
#include <stdio.h>
#pragma warning(disable:4996)

void rHnoi(int n, char from, char tmp, char to)
{
    if(n == 1){
        printf("%c %c\n", from, to); //원판이 하나일 경우 from에서 to로 옮기기
    }
    else{
        rHnoi(n-1, from, to, tmp);
        printf("%c %c\n", from, to);
        rHnoi(n-1, tmp, from, to);
    }
}


int main()
{
    int N;
    scanf("%d", &N);
    rHnoi(N, 'A', 'B', 'C');
    return 0;
}
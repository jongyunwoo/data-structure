#include <stdio.h>
#pragma warning(disable:4996)

void rHnoi(int n, char from, char tmp, char to)
{
    if(n == 1){
        printf("%c %c\n", from, to);
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
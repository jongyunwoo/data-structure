#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int main()
{
    int N, M, k = 0;
    int start, end, temp = 0;
    scanf("%d", &N);
    int X[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &X[i]);
    }
    scanf("%d", &M);
    M = M*2;
    int a[M];
    for(int i = 0; i < M; i++){
        scanf("%d", &a[i]);
    }
    for(k = 0;k < M;){
        start = a[k];
        end = a[k+1];
        k = k + 2;
        while(1){
            temp = X[start];
            X[start] = X[end];
            X[end] = temp;
            start++;
            end--;
            if(start >= end) break;
        }
    }
    for(int i = 0; i < N; i++){
        printf(" %d", X[i]);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
int main()
{
    int N, M;
    int temp;
    scanf("%d", &N);
    int *arr = (int*)malloc(N*sizeof(int));
    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &M);
    int a[M];
    int save[M-1];
    for(int i = 0; i < M; i++){
        scanf("%d", &a[i]);
    }
    temp = arr[a[M-2]];
    for(int i = 0; i < M-1; i++){
        save[i] = arr[a[i]];
    }
    for(int i = 0; i < M-1; i++){
        arr[a[i+1]] = save[i];
    }
    arr[a[0]] = temp;
    for(int i = 0; i < N; i++){
        printf(" %d", arr[i]);
    }
}
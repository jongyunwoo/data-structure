#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)


int main() 
{
    int N, M;
    int row, col = 0;
    scanf("%d %d", &N, &M);
    int **arr =(int **)malloc(N*sizeof(int*));
    for(int i = 0; i < N; i++){
        arr[i] = (int *)malloc(M*sizeof(int));
    }
    int a = 1; 

    // 대각선 방향으로 숫자 채우기,
    for(int d = 0; d < N + M - 1; d++) {
        if(d < M){
            row = 0;
            col = d;
        }
        else if(d >= M){
            row = d - M + 1;
            col = M - 1;
        }
        while(row < N && col >= 0) {
            arr[row][col] = a++;
            row++;
            col--;
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < N; i++){
        free(arr[i]);
    }
    free(arr);

    return 0;
}


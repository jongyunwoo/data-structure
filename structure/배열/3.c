#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int main()
{
    int N = 0;
    int a = 1;
    int k = 0, f = 0;
    scanf("%d", &N);
    int **arr = (int **)malloc(N*sizeof(int*));
    for(int i = 0; i < N; i++){
        arr[i] = (int *)malloc(N*sizeof(int));
    }
    while(1){
        arr[k][f] = a;
        f++;
        a++;
        if(f == N){
            k++;
            if(k == N)
                break;
            while(1){
                f--;
                if(f < 0){
                    k++;
                    break;
                }
                arr[k][f] = a;
                a++;
            }
            f++;
        if(k == N)
            break;
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf(" %d", arr[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < N; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
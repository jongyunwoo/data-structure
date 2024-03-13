#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int mostOnes(int arr[100][100], int N)
{
    int max = 0;
    int i = 0;
    int count = 0;
    for(;i < N;){
        if(arr[i][count] == 1){
            count++;
            max = i;
        }
        else i++;
    }
    return max;
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[100][100];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    printf("%d", mostOnes(arr, n));
    return 0;
}
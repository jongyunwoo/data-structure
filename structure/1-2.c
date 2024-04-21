#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int mostOnes(int arr[100][100], int N) //행렬과 행렬의 크기 입력
{
    int max = 0;
    int i = 0;
    int count = 0;
    for(;i < N;){ //행렬 크기만큼 반복
        if(arr[i][count] == 1){ //행렬값이 1이면 
            count++; //다음 열로 옮김
            max = i;
        }
        else i++; //0이면 열 증가시키지 않고 행만 다음으로 옮김
    }
    return max; //1이 가장 많은 행 출력
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[100][100]; //행렬의 최대 크기 100*100
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]); //행렬 값 입력
        }
    }
    printf("%d", mostOnes(arr, n));
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int main()
{
    int N = 0; //행렬의 크기
    int a = 1; //행렬에 들어가는 숫자, 1부터 시작
    int k = 0, f = 0; //행, 열 변수
    scanf("%d", &N); // 행렬 크기 입력
    int **arr = (int **)malloc(N*sizeof(int*)); // 행 동적할당
    for(int i = 0; i < N; i++){
        arr[i] = (int *)malloc(N*sizeof(int)); // 열 동적할당
    }
    while(1){
        arr[k][f] = a; //(0,0)부터 1로 채우기
        f++; // 열 증가
        a++; // 숫자 증가
        if(f == N){ // 마지막 열에 왔을 때
            k++; // 다음 행으로 넘어가기
            if(k == N) // 만약 마지막 행+1이면 while문 탈출
                break;
            while(1){
                f--; // index맞추기 위해 열 인덱스 하나 줄이기, 끝에서 처음으로 하나씩 열 줄이기
                if(f < 0){
                    k++; // 열 index가 음수이면 행하나 증가시키고 break
                    break;
                }
                arr[k][f] = a; // 숫자입력
                a++; // 숫자 증가
            }
            f++; //f가 음수이므로 index 0부터 다시 시작하기 위해 열 인덱스 1증가
        if(k == N) // k가 마지막행+1이면 break;
            break;
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf(" %d", arr[i][j]); //행렬출력
        }
        printf("\n");
    }
    for (int i = 0; i < N; i++) { 
        free(arr[i]); // 동적할당 해제
    }
    free(arr); //동적할당 해제

    return 0;
}
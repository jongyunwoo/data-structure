#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
int main()
{
    int N, M; //입력 수열의 길이, 순서 바꿈 정보의 길이
    int temp; //숫자 저장할 변수
    scanf("%d", &N); // 수열의 길이 입력 받기
    int *arr = (int*)malloc(N*sizeof(int)); // 배열 동적할당
    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]); // 수열값 입력 받기
    }
    scanf("%d", &M); // 순서 바꿈 정보의 길이
    int a[M]; // 순서 바꿈 정보 배열
    int save[M-1]; // 숫자값 저장할 배열 
    for(int i = 0; i < M; i++){
        scanf("%d", &a[i]); // 순서 바꿈 정보 입력 받기
    }
    temp = arr[a[M-2]]; // 순서 바꿈 정보의 마지막 숫자를 temp에 저장
    for(int i = 0; i < M-1; i++){
        save[i] = arr[a[i]]; // 순서 바꿈 정보의 숫자 save 배열에 저장
    }
    for(int i = 0; i < M-1; i++){
        arr[a[i+1]] = save[i]; // 순서 바꿈 정보를 토대로 arr 배열에 save 배열 저장
    }
    arr[a[0]] = temp; //마지막 빈 숫자 저장한 temp저장
    for(int i = 0; i < N; i++){
        printf(" %d", arr[i]); // 순서가 바뀐 배열 출력
    }
}
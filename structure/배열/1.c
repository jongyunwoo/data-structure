#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int main()
{
    int N, M, k = 0; //수열길이, 뒤집기 정보의 개수, index 변수
    int start, end, temp = 0; //숫자 저장할 변수
    scanf("%d", &N); //수열의 길이 입력
    int X[N]; //수열의 길이만큼 배열 정의
    for(int i = 0; i < N; i++){
        scanf("%d", &X[i]); //배열 입력
    }
    scanf("%d", &M); //뒤집기 정보의 개수 입력
    M = M*2; //뒤집기 구간 정보 개수
    int a[M]; // 뒤집기 구간 정보 개수만큼의 배열 선언
    for(int i = 0; i < M; i++){
        scanf("%d", &a[i]); // 뒤집기 구간 정보 입력
    }
    for(k = 0;k < M;){
        start = a[k]; 
        end = a[k+1];
        k = k + 2; // index 두 개씩 넘어가기
        while(1){
            // 순서 반대로 뒤집기
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
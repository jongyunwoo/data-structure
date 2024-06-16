#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

//구조체 정의
typedef struct{ 
    int *e; //입력받을 원소 변수
    int front; //front
    int rear; //rear
}circleQ; // 구조체 이름 원형Q

//초기화
void init(circleQ *q, int N){
    q->front = 0;
    q->rear = 0;
    q->e = (int*)malloc(sizeof(int)*N); //동적할당 받은 후
    for (int i = 0; i < N; i++){
    q->e[i] = 0; //모든 원소값 0으로 초기화
    }
}

//데이터 삽입
void INPUT(circleQ *q, int e, int N){
    if(q->front == (q->rear+1)%N){ // 데이터 삽입할 위치와 front와 같으면 overflow출력
        printf("overflow");
        for(int i = 0; i < N; i++){
            printf(" %d", q->e[i]); //모든 배열 원소들 출력 후 프로그램 종료
        }
    }
    else{
        q->rear = (q->rear+1) % N; //외우기 (rear 한 칸 뒤로 미루기)
        q->e[q->rear] = e; //삽입
    } 
}    

//데이터 삭제
void Delete(circleQ *q, int N){
    if(q->front == (q->rear)%N){ //front와 rear같다면
        printf("underflow"); //underflow 출력 후 프로그램 종료
    }
    else{
        q->front = (q->front+1)%N; // 외우기(데이터 삭제)
        q->e[q->front] = 0; //

    }
}

//데이터 출력
void Print(circleQ *q, int N){
    int i = 0;
    while(1){        
        printf("%d ", q->e[i]);
        i = (i+1);
        if(i == N){
            break;
        }
    }
}

int main(){
    int N;
    int M;
    char ch;
    int data;
    circleQ p;

    scanf("%d", &N);
    scanf("%d", &M);
    init(&p, N);

    for(int j = 0; j < M; j++){
        scanf(" %c", &ch);
        if(ch == 'I'){
            scanf("%d", &data);
            INPUT(&p, data, N);
        }
        else if(ch == 'D'){
            Delete(&p, N);

        }
        else if(ch == 'P'){
            Print(&p, N);
            printf("\n");
        }
    }
}
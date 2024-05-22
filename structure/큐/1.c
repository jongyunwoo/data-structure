#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

//구조체 정의
typedef struct{
    int *e;
    int front;
    int rear;
}circleQ;

//초기화
void init(circleQ *q, int N){
    q->front = 0;
    q->rear = 0;
    q->e = (int*)malloc(sizeof(int)*N);
}

//공백상태 여부
int empty(circleQ *q){
    if(q->front == q->rear){
        return 1;
    }
    else{
        return 0;
    }
}

//포화상태 여부
int full(circleQ *q, int N){
    if(q->front == (q->rear+1)%N){
        return 1;
    }
    else{
        return 0;
    }
}

//데이터 삽입
void INPUT(circleQ *q, int e, int N){
    if(full(q, N) == 1){
        printf("overflow ");
    }
    else{
        q->rear = (q->rear+1) % N;
        q->e[q->rear] = e;
    }
}    

//데이터 삭제
int Delete(circleQ *q, int N){
    if(empty(q) == 1){
        printf("underflow ");
        return 0;
    }
    else{
        q->front = (q->front+1)%N;
        return q->e[q->front] = 0;
    }
}

//데이터 출력
void Print(circleQ *q, int N){
    int i = 0;
    if(empty(q) == 1){
        printf("underflow ");
    }
    if(full(q, N) == 1){
        printf("overflow ");
        while(1){        
            printf("%d ", q->e[i]);
            i = (i+1);
            if(i == N+1){
                break;
            }
        }
    }
    else{
        while(1){        
            printf("%d ", q->e[i]);
            i = (i+1);
            if(i == N+1){
                break;
            }
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
    init(&p, M);

    for(int j = 0; j < M; j++){
        scanf(" %c", &ch);
        getchar();
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
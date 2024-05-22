#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

//구조체 정의
typedef struct(){
    Element *e;
    int front;
    int rear;
}circleQ;

//초기화
void init(circleQ *p){
    p->front = 0;
    p->rear = 0;
    p->e = (int*)malloc(sizeof(int)*Maxsize);
}

//공백상태 여부
int empty(circleQ *p){
    if(p->front == p->rear){
        return 1;
    }
    else{
        return 0;
    }
}

//포화상태 여부
int full(circleQ *p, N){
    if(p->front == (p->rear+1)%N){
        return 1;
    }
    else{
        return 0;
    }
}

//데이터 삽입
void INPUT(circleQ *p, Element *e, N){
    if(full(p) == 1){
        printf("overflow");
    }
    else{
        p->rear = (p->rear+1) % N;
        p->data[p->rear] = e;
    }
}    

//데이터 삭제
void Delete(circleQ *p, Element *e, N){
    if(empty(p) == 1){
        printf("underflow");
    }
    else{
        p->front= (p->front+1)%N;
        return p->data[p->front];
    }
}

//데이터 출력
void Print(circleQ p, N){
    int i = p.front;
    if(empty(&p) == 1){
        printf("underflow");
    }
    if(full(&p) == 1){
        printf("overflow")
    }
    while(1){
        i = (i+1)%N;
        printf("%d ", p.data[i]);
        if(i == p.rear){
            break;
        }
    }
}

int main(){
    int N;
    int M;
    int k;
    char ch;
    int data;
    circleQ p;
    init(&p);

    scanf("%d", &N);
    scanf("%d", &M);

    for(int j = 0; j < M; j++){
        scanf("%c %d", &ch, &data);
        if(ch == 'I'){
            INPUT(&p, data, N)
        }
    }

}
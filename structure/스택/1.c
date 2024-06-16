#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int Stacksize, top;

void push(char *S, char element){ // 삽입
    if(top >= Stacksize-1){ 
        printf("Stack FULL\n"); 
        return;
    }
    S[++(top)] = element;
}

char pop(char *S){ // 삭제
    if(top <= -1){
        printf("Stack Empty\n");
        return;
    }
    return S[(top)--]; // 삭제한 원소 반환
}

void peek(char *S){
    if(top <= -1){
        printf("Stack Empty\n");
        return;
    }
    printf("%c\n", S[top]); // top에 존재하는 원소 반환
}

void duplicate(char *S){ //stop에 있는 원소를 pop한 후 두 번 삽입
    if(top >= Stacksize-1){
        printf("Stack FULL\n");
    }
    push(S, pop(S)); 
    push(S, S[top]);
}

void upRotate(char *S, int n){ // 맨 위의 원소 n개를 하나씩 위로 올림, top은 가장 아래로
    char *array = (char *)malloc(n*sizeof(char));
    if(n > top + 1){
        free(array);
        return;
    }
    for(int i = 0; i < n; i++){
        array[i]=pop(S);
    }
    push(S, array[0]);
    for(int i = n-1; i > 0; i--){
        push(S, array[i]);
    }
    free(array);
}

void douwnRatate(char *S, int n){ // 맨위의 원소 n개를 하나씩 아래로 내림, 가장 아래 있는 원소 top으로 옮김
    char *array = (char *)malloc(n*sizeof(char));
    if(n > top + 1){
        free(array);
        return;
    }
    for(int i = 0; i < n; i++){
        array[i] = pop(S);
    }

    for(int i = n -2 ; i > -1; i--){
        push(S, array[i]);
    }
    push(S, array[n-1]);
    free(array);
}

void print(char *S){ // top에서부터 순서대로 출력
    for(int i = top; i > -1; i--){
        printf("%c", S[i]);
    }
    printf("\n");
}


int main(){
    int N, M;
    char *S, cal[6], element;
    scanf("%d", &Stacksize);
    S = (char*)malloc(Stacksize*sizeof(char));
    top = -1;

    scanf("%d", &N);
    getchar();

    for(int i = 0; i < N; i++){
        scanf("%s", cal);
        getchar();
        if(strcmp(cal, "PUSH") == 0){
            scanf("%c", &element);
            getchar();
            push(S, element);
        }
        else if(strcmp(cal, "POP") == 0){
            pop(S);
        }
        else if(strcmp(cal, "PEEK") == 0){
            peek(S);
        }
        else if(strcmp(cal, "DUP") == 0){
            duplicate(S);
        }
        else if(strcmp(cal, "DownR") == 0){
            scanf("%d", &M);
            getchar();
            douwnRatate(S, M);
        }
        else if(strcmp(cal, "UpR") == 0){
            scanf("%d", &M);
            getchar();
            upRotate(S, M);
        }
        else if(strcmp(cal, "PRINT") == 0){
            print(S);
        }
    }
    free(S);
}
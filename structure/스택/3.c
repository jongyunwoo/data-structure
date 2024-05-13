#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int Stacksize = 100;
int top;

void push(char *S, char *element){
    if(top >= Stacksize-1){
        printf("Stack Full\n");
        return;
    }
    S[++[top]] = element;
}

char pop(char *S){
    if(top <= -1){
        printf("Stack Empty\n");
        return 0;
    }
    return S[(top)--];
}

void convert(char *arr){
    char S[Stacksize] = 0;
    int i = 0;
    char s;
    while(S != ' ' || S != '\n'){
           s = arr[i];
           if(s >='A' && s <='Z'){
            printf("%c", s);
           }
           else if()
    }
}

int main(){
    
    int N;
    scanf("%d", &N);
    char array[N][Stacksize];
    char Stack[Stacksize];
    for(int i = 0; i < Stacksize; i++){
        for(int j = 0; j < 100; j++){
            scanf("%c", &array[i][j]);
        }
    }

    for(int i = 0; i < N; i++){
        convert(array[i]);
    }
}


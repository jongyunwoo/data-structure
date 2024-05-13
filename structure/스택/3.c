#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable:4996)

#define stacksize 100
char S[stacksize];
int top = -1;

void push(char c){
    if(top >= stacksize-1){
        printf("Stack Full\n");
    }
    S[++(top)] = c;
}

char pop(){
    if(top <= -1){
        printf("Stack Empty\n");
        return '\0';
    }
    return S[(top)--];
}

//우선순위 정하기
int precedence(char op){
    if(op == '!'){
        return 6;
    }
    else if(op == '*' || op == '/'){
        return 5;
    }
    else if(op == '+' || op == '-'){
        return 4;
    }
    else if(op == '>' || op == '<'){
        return 3;
    }
    else if(op == '&&'){
        return 2;
    }
    else if(op == '||'){
        return 1;
    }
}


void convert(char *arr){
    for(int i = 0; arr[i] != '\0'; i++){
        char c = arr[i];
        if(isalpha(c)){
            printf("%c", c);
        }
        else if(c == '('){
            push(c);
        }
        else if(c == ')'){
            while(top >= 0 && S[top] != '('){
                printf("%c", pop());
            }
            pop();
        }
        else{
            while(top > 0 && (precedence(c) >= precedence(S[top]))){
                printf("%c", pop());
            }
            push(c);
        }
    }
    while(top >= 0){
        printf("%c", pop());
    }
}

int main(){
    
    int N;
    scanf("%d", &N);
    getchar();

    for(int i = 0; i < N; i++){
        char array[stacksize];
        fgets(array, stacksize, stdin);
        array[strcspn(array, "\n")] = '\0';
        convert(array);
        printf("\n");
    }
}


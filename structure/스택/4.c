#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable:4996)

#define stacksize 100

int top = -1;
char S[stacksize];

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

int calculation(char *arr) {
    for(int i = 0; arr[i] != '\0'; i++) {
        char c = arr[i];
        if (isdigit(c)) {
            push(c - '0'); // Convert char to integer and push to stack
        } else{
            int operand2 = pop();
            int operand1 = pop();
            switch(c){
                case '+':
                    push(operand1 + operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
                case '*':
                    push(operand1 * operand2);
                    break;
                case '/':
                    push(operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }
        }
    }
    return pop();
}


int main(){
    int N;
    scanf("%d", &N);
    getchar();

    for(int i = 0; i < N; i++){
        char array[stacksize];
        fgets(array, stacksize, stdin);
        array[strcspn(array, "\n")] = '\0';
        printf("%d\n", calculation(array));
    }
    return 0;
}
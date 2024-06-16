#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable:4996)

#define stacksize 100 //stacksize 정의

int top = -1; //top 초기화
char S[stacksize]; //stacksize만큼의 배열 정의

void push(char c){ // 삽입
    if(top >= stacksize-1){
        printf("Stack Full\n");
    }
    S[++(top)] = c;
}

char pop(){ // 삭제 후 반환
    if(top <= -1){
        printf("Stack Empty\n");
        return '\0';
    }
    return S[(top)--];
}

int calculation(char *arr) {
    for(int i = 0; arr[i] != '\0'; i++) { //입력받은 수식이 0이 아닐 때까지 반복
        char c = arr[i];
        if (isdigit(c)) { //문자형을 int형으로 바꿔줌 ex) char c = '5'일 때 --> 정수형 5로 바꿔줌
            push(c - '0'); // Convert char to integer and push to stack
        } else{
            int operand2 = pop(); //top
            int operand1 = pop(); //top-1 값 두 개씩 계산
            switch(c){ //사칙연산
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
    int N; //수식의 개수
    scanf("%d", &N); //수식의 개수 입력 받음
    getchar(); //개행문자 처리

    for(int i = 0; i < N; i++){
        char array[stacksize]; //수식의 개수만큼 stacksize의 배열 입력받음
        fgets(array, stacksize, stdin); //입력받기
        array[strcspn(array, "\n")] = '\0'; //개행문자
        printf("%d\n", calculation(array)); // 최종 평가값 출력
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable:4996)

#define stacksize 100 // stacksize 정의

char S[stacksize]; //stack사이즈만큼 배열 정의
int top = -1; // top 초기화

void push(char c){ //삽입
    if(top >= stacksize-1){
        printf("Stack Full\n");
    }
    S[++(top)] = c;
}

char pop(){ //삭제 후 반환
    if(top <= -1){
        printf("Stack Empty\n");
        return '\0';
    }
    return S[(top)--];
}

//우선순위 정하기
int precedence(char op){
    if(op == '!' || ){
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
    else if(op == '&'){
        return 2;
    }
    else if(op == '|'){
        return 1;
    }
}


void convert(char *arr){ //중위수식 --> 후위수식으로 변환
    for(int i = 0; arr[i] != '\0'; i++){
        char c = arr[i];
        if(isalpha(c)){ //c가 알바벳일 경우 
            printf("%c", c); // 즉시 출력
        }
        else if(c == '('){ // 여는 괄호일 경우 스택에 저장
            push(c);
        }
        else if(c == ')'){ // 닫는 괄호일 경우
            while(top >= 0 && S[top] != '('){ //여는 괄호가 나올 때까지
                printf("%c", pop()); //출력
            }
            pop(); //여는 괄호는 삭제
        }
        else if(c == '&'){ //and기호일 경우
            if(S[top] == '&'){ // 만약 top이 &일 때
                if(S[top-1] == '&'){ //top-1이 &이면
                    printf("%c", pop()); // 출력
                    printf("%c", pop()); // 출력 --> &&가 하나의 기호임
                }
                push(c); //새로운 &스택에 저장
            }
            else{ //그게 아니면 
                while(top >= 0 && (precedence(c) <= precedence(S[top])) && S[top] != '('){ //우선순위 따져서
                    printf("%c", pop()); //출력
                }
                push(c); //그리고 삽입
            }

        }
        else if(c == '|'){ //&&기호와 마찬가지
            if(S[top] == '|'){
                if(S[top - 1] == '|'){
                    printf("%c", pop());
                    printf("%c", pop());
                }
                push(c);
            }
            else{
                while(top >= 0 && (precedence(c) <= precedence(S[top])) && S[top] != '('){
                    printf("%c", pop());
                }
                push(c);
            }

        }
        else{ // 나머지 기호들 우선순위 따져서 출력
            while(top >= 0 && (precedence(c) <= precedence(S[top])) && S[top] != '('){
                printf("%c", pop());
            }
            push(c);
        }
    }
    while(top >= 0){
        if(S[top] == '('){
            pop();
        }
        else{
            printf("%c", pop());
        }
    }
}

int main(){
    int N;
    scanf("%d", &N);
    getchar(); // 개행문자

    for(int i = 0; i < N; i++){
        char array[stacksize];
        fgets(array, stacksize, stdin); //stacksize만큼 입력받음
        array[strcspn(array, "\n")] = '\0'; // 개행문자 찾음
        convert(array); // 중위수식 --> 후위수식으로 변환
        printf("\n"); // 다음 줄 출력을 위해 줄 바꿈
    }
}
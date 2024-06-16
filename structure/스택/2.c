#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

char *S;
int top;

char pop(){ // 원소 삭제 후 반환
	if(top <= -1) {
        printf("Stack Empty\n");
        return 0;
    }
    return S[(top)--];
}

void push(char value){ // 원소 삽입
	if(top >= 1000 - 1){
		printf("Stack FULL\n");
		return;
	}
	S[++(top)] = value;
}

int isEmpty(){
	if((top) == -1){
		return 1;
	}
	else{
		return 0;
	}
}

int checkBalance(char *sentence){
	char popItem; 
	for(int i = 0; i < strlen(sentence); i++){
		if((sentence[i] == '(') || (sentence[i] == '{') || (sentence[i] == '[')){
			push(sentence[i]); // 시작 괄호이면 스택에 쌓음
		}
		else if((sentence[i] == ')') || (sentence[i] == '}') || (sentence[i] == ']')){
			if(isEmpty()){
				return 0;
			}
			popItem = pop(); // 닫는 괄호이면 여는 괄호 변수에 전달
			if(sentence[i] == ')'){
				if(popItem != '('){
					return 0; // 짝이 맞지 않으면 0
				}
			}
			else if(sentence[i] == '{'){
				if(popItem != '}'){
					return 0; //짝이 맞지 않으면 0
				}
			}
			else if(sentence[i] == '['){
				if(popItem != ']'){
					return 0; // 짝이 맞지 않으면 0
				}
			}
		}
	}
	return isEmpty();
}
int main(){
	int count = 0;
	char *sentence = (char*)malloc(sizeof(char) * 1000);
	S = (char*)malloc(sizeof(char) * 1000);
	top = -1;

	fgets(sentence, 1000, stdin);
	getchar();
	for(int i = 0; i < strlen(sentence); i++){
		if ((sentence[i] == '(') || (sentence[i] == '{') || (sentence[i] == '[') || (sentence[i] == ')') || (sentence[i] == '}') || (sentence[i] == ']')){
			count++; // 괄호 총 개수 구하기
		}
	}
	if(checkBalance(sentence) == 1){
		printf("OK_%d", count);
	}
	else{
		printf("Wrong_%d", count);
	}
	free(sentence);
	free(S);

}
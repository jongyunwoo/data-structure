#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

char *S;
int top;

char pop(){
	if(top <= -1) {
        printf("Stack Empty\n");
        return 0;
    }
    return S[(top)--];
}

void push(char value){
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
			push(sentence[i]);
		}
		else if((sentence[i] == ')') || (sentence[i] == '}') || (sentence[i] == ']')){
			if(isEmpty()){
				return 0;
			}
			popItem = pop();
			if(sentence[i] == ')'){
				if(popItem != '('){
					return 0;
				}
			}
			else if(sentence[i] == '{'){
				if(popItem != '}'){
					return 0;
				}
			}
			else if(sentence[i] == '['){
				if(popItem != ']'){
					return 0;
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
	for(int i = 0; i < strlen(sentence); i++){
		if ((sentence[i] == '(') || (sentence[i] == '{') || (sentence[i] == '[') || (sentence[i] == ')') || (sentence[i] == '}') || (sentence[i] == ']')){
			count++;
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
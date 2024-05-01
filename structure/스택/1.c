#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int Stacksize, top;

void push(char *S, char element){
    if(top >= Stacksize-1){
        printf("Stack FULL\n");
        return;
    }
    S[++(top)] = element;
}

char pop(char *S){
    if(top <= -1){
        printf("Stack Empty\n");
        return;
    }
    return S[(top)--];
}

void peek(char *S){
    if(top <= -1){
        printf("Stack Empty\n");
        return;
    }
    printf("%c\n", S[top]);
}

void duplicate(char *S){
    if(top >= Stacksize-1){
        printf("Stack FULL\n");
    }
    push(S, pop(S));
    push(S, S[top]);
}

void upRotate(char *S, int n){
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

void douwnRatate(char *S, int n){
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

void print(char *S){
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
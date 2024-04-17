#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SET{
    int data;
    struct SET* next;
} SET;

void member(SET* C, int e){
    SET* newelem = (SET*)malloc(sizeof(SET));
    newelem->data = e;
    newelem->next = NULL;

    while(C->next != NULL){
        C = C->next;
    }
    C->next = newelem;
}

int subset(SET* A, SET* B){
    if(A == NULL || B == NULL){
        return 0;
    }
    else{
        while (A != NULL){
            if(B == NULL){
                return A->data;
            }
            else if(A->data < B->data){
                return A->data;
            }
            else if(A->data > B->data){
                B = B->next;
            }
            else{
                A = A->next;
                B = B->next;
            }
        }
        return 0;
    }
}

void freeSET(SET* head){
    SET* tmp;
    while(head != NULL){
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main(){
    int N, M;
    int e;
    SET* A = (SET*)malloc(sizeof(SET));
    SET* B = (SET*)malloc(sizeof(SET));
    A->data = 0;
    B->data = 0;
    A->next = NULL;
    B->next = NULL;

    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &e);
        member(A, e);
    }

    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        scanf("%d", &e);
        member(B, e);
    }
    printf("%d", subset(A, B));
    freeSET(A);
    freeSET(B);

    return 0;
}

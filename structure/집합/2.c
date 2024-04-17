#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

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

SET* _union(SET *A, SET *B){
    SET* first = A;
    SET* second = B;

    SET* sum = (node*)malloc(sizeof(SET));

    if ((first->next == NULL) && (second->next == NULL))
		return sumset;
	else if (first->next == NULL) {
		free(sumset);
		return second;
	}
	else if (second->next == NULL) {
		free(sumset);
		return first;
	}
	else {
		first = first->next;
		second = second->next;

		while ((first != NULL) && (second != NULL)) {
			if (first->data < second->data) {
				addset(sumset, first->data);
				first = first->next;
			}
			else if (first->data > second->data) {
				addset(sumset, second->data);
				second = second->next;
			}
			else {
				addset(sumset, first->data);
				first = first->next;
				second = second->next;
			}
		}
		while (first != NULL) {
			addset(sumset, first->data);
			first = first->next;
		}
		while (second !=NULL) {
			addset(sumset, second->data);
			second = second->next;
		}
	}
	return sumset;
}

node* intersect(node* A, node* B) {// 이거는 교집합
	node* first = A;
	node* second = B;
	node* intersect = (node*)malloc(sizeof(node));// 교집합 담을 리스트

	intersect->data = NULL;
	intersect->next = NULL;

	if ((first->next == NULL) && (second->next == NULL)) {//둘 다 공집합이면
		return intersect;// 걍 빈 리스트 반환
    }
	else if (first->next == NULL) {// 첫번째만 공집합이어도
		return intersect;// 빈리스트 반환 왜냐믄 교집합이니께
	}
    else if (second->next == NULL) {// 어 얘도 똑같이
		return intersect;
	}
	else {// 둘다 공집합이 아니야
		first = first->next;
		second = second->next;

		while ((first != NULL) && (second != NULL)) {// 둘 중 하나가 끝나면 끝나는 반복문이
			if (first->data == second->data) {
				addset(intersect, first->data);
				first = first->next;
				second = second->next;
			}
			else if (first->data < second->data)
				first = first->next;
			else if (first->data > second->data)
				second = second->next;
		}
	}
	return intersect;
}

void print(node* set) {
	node* p = set->next;
	if (p == NULL)
		printf("0\n");
	else {
		while (p != NULL) {
			printf(" %d", p->data);
			p = p->next;
		}
		printf("\n");
	}
}

void freeset(node* set) {
	node* p = set;
	while (p != NULL) {
		set = set->next;
		free(p);
		p = set;
	}
}

int main() {
	int size, elem;
	node* A = (node*)malloc(sizeof(node));
	node* B = (node*)malloc(sizeof(node));
	node* sumset, * intersectset;
	A->data = NULL;
	A->next = NULL;
	B->data = NULL;
	B->next = NULL;

	scanf("%d", &size);
	for (int i = 0; i < size; i++) {
		scanf("%d", &elem);
		addset(A, elem);
	}
	scanf("%d", &size);
	for (int i = 0; i < size; i++) {
		scanf("%d", &elem);
		addset(B, elem);
	}

	sumset = _union(A, B);
	print(sumset);
	intersectset = intersect(A, B);
	print(intersectset);
	
	free(A);
	free(B);
	free(sumset);
	free(intersectset);

}

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
    SET* sum = (SET*)malloc(sizeof(SET));
    sum->next = NULL;

    if ((first->next == NULL) && (second->next == NULL))
		return sum;
	else if (first->next == NULL) {
		free(sum);
		return second;
	}
	else if (second->next == NULL) {
		free(sum);
		return first;
	}
	else {
		first = first->next;
		second = second->next;

		while ((first != NULL) && (second != NULL)) {
			if (first->data < second->data) {
				member(sum, first->data);
				first = first->next;
			}
			else if (first->data > second->data) {
				member(sum, second->data);
				second = second->next;
			}
			else {
				member(sum, first->data);
				first = first->next;
				second = second->next;
			}
		}
		while (first != NULL) {
			member(sum, first->data);
			first = first->next;
		}
		while (second !=NULL) {
			member(sum, second->data);
			second = second->next;
		}
	}
	return sum;
}

SET* intersect(SET* A, SET* B) {
	SET* first = A->next;
	SET* second = B->next;
	SET* intersect = (SET*)malloc(sizeof(SET));
	intersect->next = NULL;

	if ((first == NULL) || (second == NULL))
		return intersect;

	while (first != NULL && second != NULL) {
		if (first->data == second->data) {
			member(intersect, first->data);
			first = first->next;
			second = second->next;
		}
		else if (first->data < second->data)
			first = first->next;
		else if (first->data > second->data)
			second = second->next;
	}
	return intersect;
}

void print(SET* set) {
	SET* p = set->next;
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

void freeset(SET* set) {
	SET* p = set;
	SET* temp;
	while (p != NULL) {
		temp = p;
		p = p -> next;
		free(temp);
	}
}

int main() {
	int size, elem;
	SET* A = (SET*)malloc(sizeof(SET));
	SET* B = (SET*)malloc(sizeof(SET));
	SET* sumset, * intersectset;
	A->next = NULL;
	B->next = NULL;

	scanf("%d", &size);
	for (int i = 0; i < size; i++) {
		scanf("%d", &elem);
		member(A, elem);
	}
	scanf("%d", &size);
	for (int i = 0; i < size; i++) {
		scanf("%d", &elem);
		member(B, elem);
	}

	sumset = _union(A, B);
	print(sumset);
	intersectset = intersect(A, B);
	print(intersectset);
	
	freeset(A);
	freeset(B);
	freeset(sumset);
	freeset(intersectset);
}

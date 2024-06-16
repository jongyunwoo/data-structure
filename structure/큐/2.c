#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 이중연결리스트 구조체 정의
struct node{
	int element;
	struct node *next;
	struct node *prev;
};

int dequeNumber; //데크Q에 들어갈 원소
struct node *deque, *rear, *front;

void delete_front(){ //front에서 삭제
	struct node *p;
	if (dequeNumber == 0){
		printf("underflow\n");
		exit(1);
	}
	else{
		p = front;
		if (dequeNumber == 1){
			free(p);
		}
		else{
			front = front->next;
			front->prev = NULL;
			free(p);
		}
	}
}


void delete_rear(){
	struct node *p;
	if (dequeNumber == 0) {
		printf("underflow\n");
		exit(1);
	}
	else{
		p = rear;
		if (dequeNumber == 1){
			free(p);
		}
		else{
			rear = rear->prev;
			rear->next = NULL;
			free(p);
		}
	}
}

void add_front(int value){
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->element = value;
	newnode->prev = NULL;
	newnode->next = front;
	newnode->next->prev = newnode;
	front = newnode;
}

void add_rear(int value){
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->element = value;
	newnode->prev = rear;
	newnode->next = NULL;
	newnode->prev->next = newnode;
	rear = newnode;
}

void print(){
	struct node *p = front;
	while (p != NULL){
		printf(" %d", p->element);
		p = p->next;
	}
	printf("\n");
}



void freeDeque() {
	struct node *temp = front;
	while (temp != NULL) {
		front = front->next;
		free(temp);
		temp = front;
	}
}



int main(){
	int calculateSize, value;
	char calculate[5];
	dequeNumber = 0;
	scanf("%d", &calculateSize);
	getchar();
	for (int i = 0; i < calculateSize; i++){
		scanf("%s", &calculate);
		getchar();
		if (strcmp(calculate, "AF") == 0){
			scanf("%d", &value);
			getchar();
			if (dequeNumber == 0){
				deque = (struct node*)malloc(sizeof(struct node));
				deque->element = value;
				deque->next = NULL;
				deque->prev = NULL;
				front = deque;
				rear = deque;
				dequeNumber++;
			}
			else{
				add_front(value);
				dequeNumber++;
			}
		}
		else if (strcmp(calculate, "AR") == 0){
			scanf("%d", &value);
			getchar();
			if (dequeNumber == 0) {
				deque = (struct node*)malloc(sizeof(struct node));
				deque->element = value;
				deque->next = NULL;
				deque->prev = NULL;
				front = deque;
				rear = deque;
				dequeNumber++;
			}
			else {
				add_rear(value);
				dequeNumber++;
			}
		}
		else if (strcmp(calculate, "DF") == 0){
			delete_front();
			dequeNumber--;
		}
        else if (strcmp(calculate, "DR") == 0){
			delete_rear();
			dequeNumber--;
		}
		else if (strcmp(calculate, "P") == 0){
			print(&front);
		}
	}
	freeDeque();
}
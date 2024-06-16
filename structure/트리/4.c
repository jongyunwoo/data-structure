#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>

typedef struct tree //트리 구조체 정의
{
	struct tree* left; //left
	int data; //data
	struct tree* right; //right

}tree; //tree

tree* getnode(int data){ //node생성
	tree* node = (tree*)malloc(sizeof(tree));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

tree* findnode(tree* root, int data) { //노드 찾기
	tree* temp;
	if (!root) {
		return NULL;
	}
	if (root->data == data) {
		return root;
	}
	temp = findnode(root->left, data);
	if (temp) {
		return temp;
	}

	return findnode(root->right, data);
}

void linkchildren(tree* root, int data, int left, int right) { //노드 연결 
	tree* parent = findnode(root, data); //root부터 연결
	if (left != 0) {
		parent->left = getnode(left);
	}
	if (right != 0) {
		parent->right = getnode(right);
	}
}

tree* make_tree() { //트리 만들기
	int n; //노드 개수 입력 받기
	int data, l, r; //data, left, right 변수
	tree* root, *left, *right; //root, left, right 구조체 정의 

	scanf("%d", &n); //노드 개수 입력 받기

	scanf("%d %d %d", &data, &left, &right); //시작 root, left, right data 입력 받기
	root = getnode(data); 
	root->left = getnode(left);
	root->right = getnode(right);

	for (int i = 1; i < n; i++) { //시작 루트부터 연결
		scanf("%d %d %d", &data, &left, &right);
		linkchildren(root, data, left, right);
	}

	return root;
}

void traversal(tree* node, char* str) { //탐색 함수 
	if (node == NULL) { //노드가 없으면 NULL
		return;
	}
	else {
		printf("%d", node->data);
		if (*str) {
			if (*str == 'R') {
				traversal(node->right, str + 1);
			}
			else if (*str == 'L') {
				traversal(node->left, str + 1);
			}
		}
	}
}

int main(){
	int n, i; //탐색 횟수 
	int data, l, r;
	char lr[101]; //탐색정보

	tree* root = make_tree(); //트리만들기

	scanf("%d", &n); //탐색 횟수 입력 받기 
	for (i = 0; i < n; i++) {
		scanf("%s", lr); //탐색 정보 입력 받기 
		traversal(root, lr); //탐색 
		printf("\n"); //다음 출력을 위해 줄 바꿈
	}

	return 0;
}

#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>

typedef struct tree
{
	struct tree* left;
	int data;
	struct tree* right;

}tree;

tree* getnode(int data){
	tree* node = (tree*)malloc(sizeof(tree));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

tree* findnode(tree* root, int data) {
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

void linkchildren(tree* root, int data, int left, int right) {
	tree* parent = findnode(root, data);
	if (left != 0) {
		parent->left = getnode(left);
	}
	if (right != 0) {
		parent->right = getnode(right);
	}
}

tree* make_tree() {
	int n;
	int data, l, r;
	tree* root, *left, *right;

	scanf("%d", &n);

	scanf("%d %d %d", &data, &left, &right);
	root = getnode(data);
	root->left = getnode(left);
	root->right = getnode(right);

	for (int i = 1; i < n; i++) {
		scanf("%d %d %d", &data, &left, &right);
		linkchildren(root, data, left, right);
	}

	return root;
}

void traversal(tree* node, char* str) {
	if (node == NULL) {
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
	int n, i;
	int data, l, r;
	char lr[101];

	tree* root = make_tree();

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", lr);
		traversal(root, lr);
		printf("\n");
	}

	return 0;
}

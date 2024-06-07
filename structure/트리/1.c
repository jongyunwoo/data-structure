
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct node{
    int memory;
    struct node *left;
    struct node *right;
}node;

typedef struct tree{
    node *root;
    int size;
}tree;

//초기화
void init(tree *t){
    t->root = NULL;
    t->size = 0;
}

//노드 생성
node* create_node(int memory){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->memory = memory;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

//트리 구성
void create_tree(tree *t){
    node *F7 = create_node(130);
    node *F8 = create_node(80);

    // 부모 노드 생성 및 연결
    node *F6 = create_node(120);
    F6->left = F7;
    F6->right = F8;

    
    node *F4 = create_node(70);
    node *F5 = create_node(90);
    node *F2 = create_node(30);
    F2->left = F4;
    F2->right = F5;

    node *F3 = create_node(50);
    node *F1 = create_node(20);
    F3->left = NULL;
    F3->right = F6;
    F1->left = F2;
    F1->right = F3;

    t->root = F1;
    t->size = ;
}

// 특정 노드 번호에 대한 노드 찾기
node* find_node(node* root, int num, int *current){
    if(root == NULL) return NULL;
    if(*current == num) return root; 
    (*current)++;
    node *left = find_node(root->left, num, current);
    if(left != NULL) return left;
    return find_node(root->right, num, current);
}

void print_node_and_children_capacity(tree *t, int num){
    int current = 1;
    node *n = find_node(t->root, num, &current);
    if(n == NULL){
        printf("-1\n");
        return;
    }
    printf("%d", n->memory);
    if(n->left != NULL){
        printf(" %d", n->left->memory);
    }
    if(n->right != NULL){
        printf(" %d", n->right->memory);
    }
    printf("\n");
}

int main(){
    tree *t = (tree*)malloc(sizeof(tree));
    init(t);
    create_tree(t);

    int num;
    scanf("%d", &num);
    print_node_and_children_capacity(t, num);

    free(t);

    return 0;
}


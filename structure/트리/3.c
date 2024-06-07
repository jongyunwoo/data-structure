#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int id;
    int data;
    struct node *left;
    struct node *right;
}node;

//tree 생성
typedef struct tree{
    node *root;
    int size;
}tree;

//노드 생성 함수
node *create_node(int id, int data, node *left, node *right){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->id = id;
    new_node->data = data;
    new_node->left = left;
    new_node->right = right;
    return new_node;
}

//초기화
void init(tree *t){
    t->root = NULL;
    t->size = 0;
}

//트리 구성
void create_tree(tree *t){
    node *F7 = create_node(7, 130, NULL, NULL);
    node *F8 = create_node(8, 80, NULL, NULL);
    node *F6 = create_node(6, 120, F7, F8);
    node *F3 = create_node(3, 50, NULL, F6);
    node *F4 = create_node(4, 70, NULL, NULL);
    node *F5 = create_node(5, 90, NULL, NULL);
    node *F2 = create_node(2, 30, F4, F5);
    node *F1 = create_node(1, 20, F2, F3);
    t->root = F1;
    t->size = 8;
}

node* find_node(node* root, int id){
    if(root == NULL) return NULL;
    if(root->id == id) return root; 
    node *left = find_node(root->left, id);
    if (left != NULL) return left;
    return find_node(root->right, id);
}

int pre_order_sum(node *a){
    if(a == NULL) return 0;
    int sum = a->data;
    sum += pre_order_sum(a->left);
    sum += pre_order_sum(a->right);
    return sum;
}
int main(){
    int m;
    int result;
    scanf("%d", &m);
    if(m <= 0 || m >=9){
        printf("-1\n");
        return 0;
    }
    else{
        tree *t =(tree*)malloc(sizeof(tree));
        init(t);
        create_tree(t);
        int sum = 0;
        node *start_node = find_node(t->root, m);
        result = pre_order_sum(start_node);
        printf("%d", result);
        printf("\n");
    }
    return 0;

}
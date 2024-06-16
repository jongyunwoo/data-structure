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

node *nodes[8];
//트리구성
void create_tree(tree *t){
    nodes[6] = create_node(7, 130, NULL, NULL);
    nodes[7] = create_node(8, 80, NULL, NULL);
    nodes[5] = create_node(6, 120, nodes[6], nodes[7]);
    nodes[4] = create_node(3, 50, NULL, nodes[5]);
    nodes[2] = create_node(4, 70, NULL, NULL);
    nodes[3] = create_node(5, 90, NULL, NULL);
    nodes[1] = create_node(2, 30, nodes[2], nodes[3]);
    nodes[0] = create_node(1, 20, nodes[1], nodes[4]);
    t->root = nodes[0];
    t->size = 8;
}

node* find_node(node* root, int id){
    if(root == NULL) return NULL;
    if(root->id == id) return root; 
    node *left = find_node(root->left, id);
    if (left != NULL) return left;
    return find_node(root->right, id);
}

int pre_order_sum(node *a){ //전위순회 방식으로 원소값 더하기
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
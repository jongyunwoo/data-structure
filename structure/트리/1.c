#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int memory;
    struct node *left;
    struct node *right;
} node;

// 노드 생성 함수
node* create_node(int memory, node *left, node *right) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->memory = memory;
    new_node->left = left;
    new_node->right = right;
    return new_node;
}

// 배열을 사용하여 노드들을 저장
node* nodes[8];  // 전역 변수로 노드 포인터 배열을 선언

void create_tree() {
    // 노드 생성 및 배열에 저장
    nodes[6] = create_node(130, NULL, NULL);  // F7
    nodes[7] = create_node(80, NULL, NULL);   // F8
    nodes[5] = create_node(120, nodes[6], nodes[7]);  // F6
    nodes[3] = create_node(70, NULL, NULL);   // F4
    nodes[4] = create_node(90, NULL, NULL);   // F5
    nodes[1] = create_node(30, nodes[3], nodes[4]);  // F2
    nodes[2] = create_node(50, NULL, nodes[5]);  // F3
    nodes[0] = create_node(20, nodes[1], nodes[2]);  // F1
}

void print_node_and_children(int node_index) {
    if (node_index < 0 || node_index >= 8) {
        printf("-1\n");
        return;
    }

    node *n = nodes[node_index];
    printf("%d", n->memory);
    if (n->left) printf(" %d", n->left->memory);
    if (n->right) printf(" %d", n->right->memory);
    printf("\n");
}

int main() {
    create_tree();
    int n;
    scanf("%d", &n);
    print_node_and_children(n - 1);  // 입력된 번호를 인덱스로 변환
    return 0;
}
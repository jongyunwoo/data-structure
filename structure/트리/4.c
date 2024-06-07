#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int number;
    struct node *left;
    struct node *right;
} node;

// 트리 구조체
typedef struct tree {
    node *root;
    int size;
} tree;

// 트리 초기화
void init(tree *t) {
    t->root = NULL;
    t->size = 0;
}

// 새로운 노드 생성
node *create_node(int number) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->number = number;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// 트리에서 노드 연결
void connect_node(node **nodes, int index, int left_index, int right_index) {
    if (left_index != 0) {
        nodes[index]->left = nodes[left_index];
    }
    if (right_index != 0) {
        nodes[index]->right = nodes[right_index];
    }
}

// 입력 데이터를 바탕으로 트리 생성
void build_tree(tree *t, int n, int node_info[][3]) {
    node **nodes = (node **)malloc((n + 1) * sizeof(node *));
    for (int i = 0; i <= n; i++) {
        nodes[i] = NULL;
    }
    for (int i = 0; i < n; i++) {
        int number = node_info[i][0];
        nodes[number] = create_node(number);
    }
    for (int i = 0; i < n; i++) {
        int number = node_info[i][0];
        int left_index = node_info[i][1];
        int right_index = node_info[i][2];
        connect_node(nodes, number, left_index, right_index);
    }
    t->root = nodes[node_info[0][0]];
    t->size = n;
    free(nodes);
}

// 탐색 경로를 바탕으로 트리를 탐색
void traverse_tree(node *root, char *path) {
    node *current = root;
    if (current == NULL) return; 

    printf(" %d", current->number);
    for (int i = 0; path[i] != '\0'; i++) {
        if (path[i] == 'L') {
            current = current->left;
        } 
        else if (path[i] == 'R') {
            current = current->right;
        }
        if (current != NULL) {
            printf(" %d", current->number);
        } else {
            break;
        }
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    int node_info[n][3];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &node_info[i][0], &node_info[i][1], &node_info[i][2]);
    }

    tree t;
    init(&t);
    build_tree(&t, n, node_info);

    int s;
    scanf("%d", &s);

    char path[101];
    for (int i = 0; i < s; i++) {
        scanf("%s", path);
        traverse_tree(t.root, path);
    }

    return 0;
}

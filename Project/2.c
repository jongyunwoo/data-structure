#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 노드 구조체 생성
typedef struct node {
    char english; //A, B, C... 이름 생성
    struct node *left; //좌측
    struct node *right; // 우측
} node; // 노드 구조체 이름

// 트리 구조체 생성
typedef struct tree {
    node *root;
    int size;
} tree; // 트리 구조체 이름

// 트리 초기화
void init(tree *t) {
    t->root = NULL; //처음은 NULL
    t->size = 0; // 처음 사이즈 0
}

// 새로운 노드 생성
node *create_node(char english) {
    node *new_node = (node *)malloc(sizeof(node)); //동적할당
    new_node->english = english; // 입력받은 알파벳 입력
    new_node->left = NULL; //왼쪽 노드
    new_node->right = NULL; // 오른쪽 노드
    return new_node; // 새로 만든 노드 반환
}

// 트리에서 노드 연결
void connect_node(node **nodes, char english, char left_index, char right_index) {
    if (left_index != NULL) { // index == 알파벳
        nodes[english]->left = nodes[left_index];  // 왼쪽 노드에 알파벳 존재하면 왼쪽으로 연결
    }
    if (right_index != NULL) { // index == 알파벳
        nodes[english]->right = nodes[right_index]; // 오른쪽 노드에 알파벳 존재하면 오른쪽으로 연결
    }
}


// 입력 데이터를 바탕으로 트리 생성
void build_tree(tree *t, int n, char node_info[][3]) {
    node **nodes = (node **)malloc((n + 1) * sizeof(node *));
    for (int i = 0; i <= n; i++) {
        nodes[i] = NULL; // nodes 초기화
    }
    for (int i = 0; i < n; i++) {
        char english = node_info[i][0]; // main함수에서 받은 세 개의 알파벳 중 가장 앞에 있는 알파벳으로 노드 생성
        nodes[english] = create_node(english); // 총 트리 사이즈 만큼 노드 생성
    }
    for (int i = 0; i < n; i++) {
        char english = node_info[i][0]; // main 함수에서 받은 세 개의 알파벳 중 가장 앞에 있는 알파벳
        char left_index = node_info[i][1]; // main 함수에서 받은 세 개의 알파벳 중 두 번째 있는 알파벳을 왼쪽 자식 노드 index로 활용
        char right_index = node_info[i][2]; // main 함수에서 받은 세 개의 알파벳 중 세 번째에 있는 알파벳을 오른쪽 자식 노드 index로 활용
        connect_node(nodes, english, left_index, right_index); // 생성한 노드 연결
    } 
    t->root = nodes[node_info[0][0]]; //root 노드를 tree 구조체의 root로 연결
    t->size = n; // 트리 사이즈를 tree 구조체의 size로 연결
    free(nodes); // 동적할당 해제
} 
//전위 순회
void pre_order(node *a){
    if(a == NULL) return; //노드가 . 일 경우 반환 
    printf("%c", a->english); //root부터 출력 
    pre_order(a->left); // root기준으로 왼쪽으로 출력
    pre_order(a->right); // root기준으로 왼쪽 출력 후 오른쪽 출력
}

//중위 순회
void in_order(node *a){
    if(a == NULL) return; // 노드가 . 일 경우 반환
    in_order(a->left); // 왼쪽 가장 아래 자식 노드부터 출력
    printf("%c", a->english); // 노드 알파벳 출력
    in_order(a->right); // 왼쪽 출력 후 오른쪽 자식 노드 출력
}

//후위 순회
void post_order(node *a){ 
    if(a == NULL) return; // 노드가 . 일 경우 반환
    post_order(a->left); // root 기준 가장 오른쪽 아래 자식 노드부터 출력
    post_order(a->right); // 그 후 왼쪽으로 출력
    printf("%c", a->english); // 노드 알파벳 출력
}

int main(){
    int n; // 트리의 사이즈 입력 받을 변수
    scanf("%d", &n); // 트리 사이즈 입력
    char node_info[n][3]; // 알파벳 입력받을 배열
    for(int i = 0; i < n; i++){
        getchar(); //개행문자 처리
        scanf("%c %c %c", &node_info[i][0], &node_info[i][1], &node_info[i][2]); // 알파벳 입력
        
    }

    tree t; // 트리 구조체 이름 t
    init(&t); // t트리 초기화
    build_tree(&t, n, node_info); //입력받은 알파벳과 트리 사이즈를 이용하여 tree 생성

    pre_order(t.root); // 트리를 전위 순회로 출력
    printf("\n"); // 다음 출력을 위해 줄 바꿈
    in_order(t.root); // 트리를 준위 순회로 출력 
    printf("\n"); // 다음 출력을 위해 줄 바꿈
    post_order(t.root); // 트리를 후위 순회로 출력
}
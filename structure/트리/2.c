#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node { // 노드 구조체 정의
    int id; // id
    int data; // data
    struct node *left; //왼쪽 노드
    struct node *right; //오른쪽  노드
}node; // 노그 구조체 이름

//tree 생성
typedef struct tree{ // 트리 구조체 정의
    node *root; // root 노드
    int size; // 트리 사이즈
}tree; //트리 구조체 이름 

node *nodes[8]; //전역변수로 생성할 노드 개수

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

node* find_node(node* root, int id){ //시작노드 찾기, 재귀함수로 정의
    if(root == NULL) return NULL; //트리가 없으면 NULL출력
    if(root->id == id) return root; // 찾는 id가 root노드이면 root node 출력
    node *left = find_node(root->left, id); // 찾는 id가 root node의 왼쪽이면 node left에 저장
    if (left != NULL) return left; //left가 없으면 그대로 left 출력
    return find_node(root->right, id); // 왼쪽이 아니면 오른쪽
}

void pre_order(node *a){ //전위순회
    if(a == NULL) return;
    printf(" %d", a->data);
    pre_order(a->left);
    pre_order(a->right);
}


void in_order(node *a){ //중위순회
    if(a == NULL) return;
    in_order(a->left);
    printf(" %d", a->data);
    in_order(a->right);
}

void post_order(node *a){ //후위순회
    if(a == NULL) return;
    post_order(a->left);
    post_order(a->right);
    printf(" %d", a->data);
}


int main(){
    int n, m;
    int current = 1;
    scanf("%d %d", &n, &m);
    if(n < 1 || n > 3 || m <= 0 || m >=9){
        printf("-1\n"); //노드 id가 벗어나면 -1출력
    }
    tree *t =(tree*)malloc(sizeof(tree)); //tree
    init(t); //초기화
    create_tree(t); //트리생성
    
    node *start_node = find_node(t->root, m); //시작 노드 찾기
    if(n == 1){
        pre_order(start_node); 
    }
    else if(n == 2){
        in_order(start_node);
    }
    else if(n == 3){
        post_order(start_node);
    }
    else{
        printf("-1\n");
    }

    printf("\n");
    return 0;

}
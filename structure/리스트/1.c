#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char e;
    struct Node* prev;
    struct Node* next;
} Node;

Node* getNode() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void putNode(Node* p) {
    free(p);
}

Node* init(Node** H, Node** T) {
    *H = getNode();
    *T = getNode();
    (*H)->next = *T;
    (*T)->prev = *H;
    return *H;
}

void print(Node* H, Node* T) {
    Node* p = H->next;
    while (p != T){
        printf("%c", p->e);
        p = p->next;
    }
    printf("\n");
}

void addNodeBefore(Node* p, char e) {
    Node* newNode = getNode();
    newNode->e = e;
    newNode->prev = p->prev;
    newNode->next = p;
    p->prev->next = newNode;
    p->prev = newNode;
}

void add(Node* H, Node* T, int r, char e, int* n) {
    if (r < 1 || r > (*n) + 1) {
        printf("invalid position");
        return;
    }
    Node* p = H;
    for (int i = 0; i < r; i++) {
        p = p->next;
    }
    addNodeBefore(p, e);
    n = n + 1;
}

char removeNode(Node* p) {
    char e = p->e;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    putNode(p);
    return e;
}

char delete(Node* H, Node* T, int r, int* n) {
    if (r < 1 || r > *n) {
        printf("invalid position");
        return;
    }
    Node* p = H;
    for (int i = 0; i < r; i++) {
        p = p->next;
    }
    char e = removeNode(p);
    n = n - 1;
    return 0;
}

char get(Node* H, Node* T, int r, int *n){
    
    if ((r < 1) || (r > *n)) {
        printf("invalid position");
        return;
    }
    Node *p = H;
    Node *q = T;
    char e = p->e;
    for (int i = 0; i < r; i++) {
        if (p->next == q) {
            printf("invalid position");
            return;
        }
        p = p->next;
    }
    return p->e;
}

int main() {
    Node* H = NULL;
    Node* T = NULL;
    char List = init(&H, &T);
    int n = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char operation;
        int r;
        char e;
        scanf(" %c %d", &operation, &r);
        if (operation == 'A') {
            scanf(" %c", &e);
            add(H, T, r, e, &n);
        } else if (operation == 'D') {
            delete(H, T, r, &n);
        } else if (operation == 'G') {
            printf("%c\n", get(H, T, r, &n));
        } else if (operation == 'P') {
            print(H, T);
        }
    }

    return 0;
}

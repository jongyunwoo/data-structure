#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int priority; // (중요도)
    int index; // 원래 위치
    int rank; // 우선순위
} Node;

void processQueue(int n, Node nodes[], int target){
    for(int i = 0; i < n; i++){
        int count = 0; // rank를 계산하기 위한 변수
        for(int j = 0; j < n; j++){
            if(nodes[i].priority < nodes[j].priority){ 
                count++; // 자신의 중요도가 다른 값들의 중요도 보다 작으면 count 증가 
            }
        nodes[i].rank = count; // count변수를 rank에 저장 
        }
    }
    for(int i = 0; i < n; i++){
        if(nodes[i].rank == target){ //찾고자 하는 문서와 rank가 같다면 
            printf("%d", nodes[i].index + 1); //위치 + 1을 하여 출력
        }
    }

}

int main(){
    int N; // Q 개수를 받는 변수
    scanf("%d", &N); // Q 개수 입력 받기

    while (N--) { // Q 개수가 0이 될 때까지 반복(Q 개수만큼 반복)
        int n, target; // 노드 개수와 궁금한 문서의 변수
        scanf("%d %d", &n, &target); // 노드 개수 궁금한 문서 입력 받기

        Node nodes[n]; // 노드 배열 선언, 큐의 뒤로 보내기 위해 2*n 크기로 할당
        for (int i = 0; i < n; i++) { // 문서 개수만큼 반복
            scanf("%d", &nodes[i].priority); // 중요도 입력 받기
            nodes[i].index = i; // index 설정
        }

        processQueue(n, nodes, target); // 중요도계산 및 위치 출력
    }

    return 0;
}
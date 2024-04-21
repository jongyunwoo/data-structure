// 최댓값 출력 프로그램
#include <stdio.h>
#pragma warning(disable:4996)

int max(int *arr, int i){ //최댓값 구하는 함수
    if(i == 0){
        return arr[0]; //입력받은 값이 1개일 때 바로 반환 
    }
    // 첫 번째수부터 마지막 수와 비교하면서 최댓값구하기
    int m = max(arr, i-1);
    if(m > arr[i]){
        return m;
    }
    else{
        return arr[i];
    }
}

int main()
{
    int arr[20]; //최대 20개
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]); //배열 입력 받기
    }
    printf("%d", max(arr,n-1));
    return 0;
}

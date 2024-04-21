// 누적평균 구하기
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int *prefixAverages1(int *p, int N)
{
    double sum = 0;
    int *arr2 = (int *)malloc(N*sizeof(int));
    for(int i = 0; i < N; i++){
        sum = 0;
        for(int j = 0; j <= i; j++){
            sum = sum + p[j]; // 처음부터 들어온 값까지 다시 평균 계산
        }
        arr2[i] = (sum/(i+1)) + 0.5; // int 형이므로 0.5를 더하여 반올림 정수로 만들기
    }
    return arr2;
}

int *prefixAverages2(int *q, int N)
{
    double sum = 0;
    int *arr3 = (int *)malloc(N*sizeof(int));
    for(int i = 0; i < N; i++){
        sum += q[i]; // sum변수에 저장 후 새로 입력받은 값만 더하여 다시 평균구하기
        arr3[i] = (sum/(i+1)) + 0.5;
    }
    return arr3;
}

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int *result1 = prefixAverages1(arr, n);
    int *result2 = prefixAverages2(arr, n);

    for(int i = 0; i < n; i++){
        printf("%d ", result1[i]);
    }
    printf("\n");

    for(int i = 0; i < n; i++){
        printf("%d ", result2[i]);
    }

    free(result1);
    free(result2);
    free(arr);

    return 0;
}
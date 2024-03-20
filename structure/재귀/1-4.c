#include <stdio.h>
#pragma warning(disable:4996)

int max(int *arr, int i){
    if(i == 0){
        return arr[0];
    }
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
    int arr[20];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("%d", max(arr,n-1));
    return 0;
}

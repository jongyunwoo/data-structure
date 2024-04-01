#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int main()
{
   int N, M;
   int a = 1;
   int i, j = 0;
   scanf("%d %d", &N, &M);
   int arr[N][M] = {0};
   for(;i < M;){
      arr[j][i] = a;
      i++;
      a++;
      
   }
}
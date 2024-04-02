#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int main()
{
   int N, M;
   int a = 1;
   int i = 0, j = 0;
   scanf("%d %d", &N, &M);
   int **arr = (int **)malloc(N * sizeof(int *));
   for (int i = 0; i < N; i++){
      arr[i] = (int *)malloc(M * sizeof(int));
   }
   int countN = N;
   int countM = M;
   int countm = 0;
   int countn = 0;
   while(a <= N*M){
      for(;;){
         arr[j][i] = a;
         i++;
         a++;
         if(i == countM){
            i--;
            j++;
            countM--;
            break;
         }
      }
      for(;;){
         arr[j][i] = a;
         a++;
         j++;
         if(j == countN){
            j--;
            i--;
            countN--;
            break;
         }
      }
      for(;;){
         arr[j][i] = a;
         i--;
         a++;
         if(i < countm){
            i++;
            j--;
            countm++;
            break;
         }
      }
      for(;;){
         arr[j][i] = a;
         a++;
         j--;
         if(j == countn){
            i++;
            j++;
            countn++;
            break;
         }
      }
   }
   for(int k = 0; k < N; k++){
      for(int f = 0; f < M; f++){
         printf(" %d", arr[k][f]);
      }
      printf("\n");
   }
   return 0;
}
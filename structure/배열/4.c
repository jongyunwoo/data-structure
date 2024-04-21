#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int main()
{
   int N, M; //(N,M) 행렬 크기 변수
   int a = 1; // 행렬에 들어갈 숫자 변수
   int i = 0, j = 0; // 행, 열 index
   scanf("%d %d", &N, &M);
   int **arr = (int **)malloc(N * sizeof(int *)); // 행 동적할당
   for (int i = 0; i < N; i++){
      arr[i] = (int *)malloc(M * sizeof(int)); // 열 동적할당
   }
   int countN = N;
   int countM = M;
   int countm = 0;
   int countn = 0;
   while(1){
      //왼쪽에서 오른쪽으로
      for(;;){
         arr[j][i] = a; // 열 증가시키면서 숫자 증가
         i++;
         a++;
         if(i == countM){ // 열이 행렬의 열크기일때
            i--; // index 맞추기 위하여 1감소
            j++; // 행 증가
            countM--; // 열 크기 감소
            break; //for 문 탈출
         }
      }
      if(a > N*M) break; // while 문 탈출

      // 위에서 아래로
      for(;;){
         arr[j][i] = a; //행 증가시키면서 숫자 증가
         a++;
         j++;
         if(j == countN){ // 행이 행렬의 행크기일때
            j--; // 행 index 맞추기 위해 1감소
            i--; // 열 index 하나 줄이기
            countN--; //행 크기 감소
            break; // for문 탈출
         }
      }
      if(a > N*M) break; // while 문 탈출
      //오른쪽에서 왼쪽으로
      for(;;){
         arr[j][i] = a; //열 하나씩 감소하면서 숫자증가
         i--;
         a++; 
         if(i < countm){ 
            i++;
            j--;
            countm++;
            break;
         }
      }
      if(a > N*M) break;
      //아래서 위쪽으로
      for(;;){
         arr[j][i] = a;
         a++;
         j--;
         if(j <= countn){  
            i++;
            j++;
            countn++;
            break;
         }
      }
      if(a > N*M) break;

   }
   for(int k = 0; k < N; k++){
      for(int f = 0; f < M; f++){
         printf(" %d", arr[k][f]);
      }
      printf("\n");
   }
   return 0;
}
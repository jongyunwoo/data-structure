// 문자열안에 특정한 문자가 몇 번 들어가 있는지 출력하는 프로그램
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int check(char *arr, char c, int idx, int count)
{
    if(arr[idx] == c){
        count++; //index문자가 비교하는 문자와 같을 경우 count증가
        return check(arr, c, idx+1, count); //다음 index확인
    }
    else if(arr[idx] == '\0'){
        return count; // 끝까지 확인하였을 경우 count 반환
    }
    else{
        return check(arr, c, idx+1, count); // 비교하는 문자와 같지 않울 경우 다음 index문자 확인
    }
}

int main()
{
    char arr[100];
    char s;
    int i = 0;
    scanf("%s", arr); //문자열입력
    getchar(); //개행문자
    scanf("%c", &s); // 검사할 문자
    printf("%d", check(arr, s, i, 0));
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int check(char *arr, char c, int idx, int count)
{
    if(arr[idx] == c){
        count++;
        return check(arr, c, idx+1, count);
    }
    else if(arr[idx] == '\0'){
        return count;
    }
    else{
        return check(arr, c, idx+1, count);
    }
}

int main()
{
    char arr[100];
    char s;
    int i = 0;
    scanf("%s", arr);
    getchar();
    scanf("%c", &s);
    printf("%d", check(arr, s, i, 0));
    return 0;
}
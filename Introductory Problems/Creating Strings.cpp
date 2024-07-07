
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
 
int count = 0;
char dp[100000][10];
int compare(const void*xvoid, const void*yvoid){
    char x=*(char*)xvoid;
    char y=*(char*)yvoid;
    return x-y;
}
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}
void reverse(char arr[], int start, int end) {
    while (start < end) {
        swap(&arr[start], &arr[end]);
        start++;
        end--;
    }
}
bool next_permutation(char arr[]) {
    int n = strlen(arr);
    int i = n - 2;
    while (i >= 0 && arr[i] >= arr[i + 1]) {
        i--;
    }
    if (i < 0) {
        return false;
    }
    int j = n - 1;
    while (arr[j] <= arr[i]) {
        j--;
    }
    swap(&arr[i], &arr[j]);
    reverse(arr, i + 1, n - 1);
    return true;
}
 
int main() {
    char string[10];
    scanf("%s", string);
    qsort(string,strlen(string),sizeof(char),compare);
    strcpy(dp[count], string);
    while (next_permutation(string)) {
        count++;
     strcpy(dp[count], string);
 
    }
    printf("%d\n",count+1);
     for (int i = 0; i < count+1; i++) {
        printf("%s\n", dp[i]);
    }
 
    return 0;
}

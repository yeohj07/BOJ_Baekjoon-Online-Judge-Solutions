#include<stdio.h>
#include<string.h>

void mergeSort(char word[][51], char temp[][51], int start, int end) {
    int i = start, k = start, mid = (start + end)/2;
    int j = mid + 1;
    if(start >= end) return;
    mergeSort(word, temp, start, mid);
    mergeSort(word, temp, mid + 1, end);
    while((i <= mid) && (j <= end)) {
        if(strlen(word[i]) < strlen(word[j]) || (strlen(word[i]) == strlen(word[j]) && strcmp(word[i], word[j]) < 0)) temp[k][0] = '\0', strcpy(temp[k++], word[i++]);
        else temp[k][0] = '\0', strcpy(temp[k++], word[j++]);
    }
    while(i <= mid) temp[k][0] = '\0', strcpy(temp[k++], word[i++]);
    while(j <= end) temp[k][0] = '\0', strcpy(temp[k++], word[j++]);
    for(i=start; i<=end; i++) word[i][0] = '\0', strcpy(word[i], temp[i]);
}

int main() {
    int n;
    char word[20001][51], temp[20001][51];
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%s", word[i]);
    mergeSort(word, temp, 0, n-1);
    for(int i=0; i<n; i++) {
        if(!strcmp(word[i], word[i+1])) continue;
        printf("%s\n", word[i]);
    }
}

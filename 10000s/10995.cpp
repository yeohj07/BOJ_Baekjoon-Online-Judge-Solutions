#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=2*n; j++) {
            if((i+j)%2 == 0) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
}

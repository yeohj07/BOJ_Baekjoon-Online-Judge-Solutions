#include<stdio.h>

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if(a+d > b+c) printf("%d", a+d-b-c);
    else printf("%d", b+c-a-d);
}

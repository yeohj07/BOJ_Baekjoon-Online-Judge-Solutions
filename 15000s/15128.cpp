#include<stdio.h>

int main() {
    int p1, q1, p2, q2, temp;
    scanf("%d %d %d %d", &p1, &q1, &p2, &q2);
    if(((long long int)p1*p2)%(2*q1*q2) == 0) printf("1");
    else printf("0");
}

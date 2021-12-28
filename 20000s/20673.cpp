#include <cstdio>
using namespace std;

int Abs(int a, int b) { return a-b>=0?a-b:b-a; }

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    if(a <= 50 && b <= 10) printf("White");
    else if(b >= 30) printf("Red");
    else printf("Yellow");
}

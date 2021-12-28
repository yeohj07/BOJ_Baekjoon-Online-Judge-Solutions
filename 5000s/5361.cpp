#include <iostream>
using namespace std;

int main() {
    int T;
    double a, b, c, d, e;
    scanf("%d", &T);
    for(int i=0; i<T; i++) {
        scanf("%lf %lf %lf %lf %lf", &a, &b, &c, &d, &e);
        printf("$%.2lf\n", a*350.34+b*230.90+c*190.55+d*125.30+e*180.90);
    }
}

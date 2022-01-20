#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, d;
    cin >> N >> d;

    int Begin, End = pow(d, d);
    if(N < pow(d, d-1)) Begin = pow(d, d-1);
    else Begin = N+1;

    for(int i=Begin; i<=End; i++) {
        int check[10] = {}, temp = i;
        while(temp) {
            check[temp%d]++;
            temp /= d;
        }
        bool isComplete = true;
        for(int i=0; i<d; i++)
            if(check[i] != 1) isComplete = false;
        if(isComplete) {
            cout << i;
            return 0;
        }
    }
    cout << "-1";
}

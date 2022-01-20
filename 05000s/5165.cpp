#include <bits/stdc++.h>
#define ull unsigned long long
#define int128 __int128
using namespace std;

int128 Base[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

int128 Power(int128 x, int128 y, int128 mod) { // ret = (x^y)%mod
    x %= mod;
    int128 ret = 1;
    while(y > 0) {
        if(y%2 == 1) ret = (ret*x)%mod;
        x = (x*x)%mod;
        y /= 2;
    }
    return ret;
}

bool isPrime(int128 n, int128 a) {
    if(a%n == 0) return true;

    int128 k = n-1;
    while(1) {
        int128 temp = Power(a, k, n);
        if(temp == n-1) return true;
        if(k%2 == 1) return (temp == 1 || temp == n-1);
        k /= 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, compositeN = 0;
    cin >> N;
    for(int i=0; i<N; i++) {
        ull input;
        cin >> input;
        int128 A = input;
        for(int j=0; j<4; j++)
            if(!isPrime(A*2+1, Base[j])) {
                compositeN++;
                break;
            }
    }
    cout << N - compositeN;
}

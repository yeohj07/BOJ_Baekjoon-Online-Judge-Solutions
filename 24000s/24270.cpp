#include <bits/stdc++.h>
#define ull unsigned long long
#define mod 1000000007
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ull N, K;
    cin >> N >> K;

    vector<ull> S; S.resize(N);
    ull R = K;
    for(int i=0; i<N; i++) {
        cin >> S[i];
        R -= S[i];
    }

    ull Ans = 1;
    for(ull i=R+1; i<=N+R; i++)
        Ans = (Ans*i)%mod;
    cout << Ans;
}

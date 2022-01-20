#include <bits/stdc++.h>
using namespace std;
const int MAX = 205;

vector<int> Adj[MAX];
int Left[MAX], Right[MAX];
bool Visit[MAX];

bool DFS(int from) {
    Visit[from] = true;
    for(int i=0; i<Adj[from].size(); i++) {
        int to = Adj[from][i];
        if(Right[to] == -1 || (!Visit[Right[to]] && DFS(Right[to]))) {
            Left[from] = to, Right[to] = from;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    while(M--) {
        int from, to;
        cin >> from >> to;
        if(from%2 == 0 && to%2 == 0) continue;
        if(from%2 == 1 && to%2 == 1) continue;
        if(from%2 == 0 && to%2 == 1) swap(from, to);
        Adj[from].push_back(to);
    }

    int match = 0;
    fill(Left, Left+MAX, -1), fill(Right, Right+MAX, -1);
    for(int i=1; i<=N; i++) {
        fill(Visit, Visit+MAX, false);
        if(DFS(i)) match++;
    }

    if(match*2 < N) cout << match*2+1;
    else cout << match*2;
}

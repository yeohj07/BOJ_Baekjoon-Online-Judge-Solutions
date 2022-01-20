#include <bits/stdc++.h>
using namespace std;
const int MSIZE = 85, MAX = 6405;

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

    int T; cin >> T;
    while(T--) {
        for(int i=0; i<MAX; i++) vector<int>().swap(Adj[i]);

        int N, M, cnt = 0; cin >> N >> M;
        char Map[MSIZE][MSIZE];
        for(int i=1; i<=N; i++) {
            cin.clear();
            for(int j=1; j<=M; j++) {
                cin >> Map[i][j];
                if(Map[i][j] == '.') cnt++;
            }
        }

        int dir[2][6] = {{-1, 0, 1, -1, 0, 1}, {-1, -1, -1, 1, 1, 1}};
        for(int i=1; i<=N; i++)
            for(int j=1; j<=M; j++)
                for(int k=0; k<6; k++) {
                    if(Map[i][j] == 'x') continue;
                    int iNext = i + dir[0][k], jNext = j + dir[1][k];
                    if(iNext >= 1 && iNext <= N && jNext >= 1 && jNext <= M && Map[iNext][jNext] == '.')
                        Adj[(i-1)*80+j].push_back((iNext-1)*80+jNext);
                }

        int match = 0;
        fill(Left, Left+MAX, -1), fill(Right, Right+MAX, -1);
        for(int i=1; i<=N; i++)
            for(int j=1; j<=M; j+=2) {
                fill(Visit, Visit+MAX, false);
                if(DFS((i-1)*80+j)) match++;
            }

        cout << cnt - match << "\n";
    }
}

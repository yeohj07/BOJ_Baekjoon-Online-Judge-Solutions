#include <bits/stdc++.h>
#define MAX 305
#define INF 1e9
using namespace std;

vector<int> Line[MAX];
vector<pair<int, int>> LineInfo;
int Capacity[MAX][MAX], Flow[MAX][MAX];

void AddLine(int From, int To, int Amount) {
    Line[From].push_back(To), Line[To].push_back(From);
    Capacity[From][To] += Amount;
    LineInfo.push_back({From, To});
}

void MaxFlow(int Sour, int Sink) {
    while(true) {
        int Parent[MAX]; fill(Parent, Parent+MAX, -1);
        queue<int> Queue; Queue.push(Sour);

        while(!Queue.empty() && Parent[Sink] == -1) {
            int Curr = Queue.front(); Queue.pop();
            for(int i=0; i<Line[Curr].size(); i++) {
                int Next = Line[Curr][i];
                if(Capacity[Curr][Next] - Flow[Curr][Next] > 0 && Parent[Next] == -1) {
                    Queue.push(Next);
                    Parent[Next] = Curr;
                }
            }
        }
        if(Parent[Sink] == -1) break;

        int Amount = INF;
        for(int i=Sink; i!=Sour; i=Parent[i])
            Amount = min(Amount, Capacity[Parent[i]][i] - Flow[Parent[i]][i]);
        for(int i=Sink; i!=Sour; i=Parent[i]) {
            Flow[Parent[i]][i] += Amount;
            Flow[i][Parent[i]] -= Amount;
        }
    }
}

bool CheckEdge(int Sour, int Sink) {
    int Parent[MAX]; fill(Parent, Parent+MAX, -1);
    queue<int> Queue; Queue.push(Sour);

    while(!Queue.empty() && Parent[Sink] == -1) {
        int Curr = Queue.front(); Queue.pop();
        for(int i=0; i<Line[Curr].size(); i++) {
            int Next = Line[Curr][i];
            if(Capacity[Curr][Next] - Flow[Curr][Next] > 0 && Parent[Next] == -1) {
                Queue.push(Next);
                Parent[Next] = Curr;
            }
        }
    }
    if(Parent[Sink] == -1) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
        fill(&Capacity[0][0], &Capacity[MAX-1][MAX], 0);
        fill(&Flow[0][0], &Flow[MAX-1][MAX], 0);
        for(int i=0; i<MAX; i++) Line[i].clear();
        LineInfo.clear();

        int N, M;
        cin >> N >> M;
        int Sour = 1, Sink = N;
        for(int i=0; i<M; i++) {
            int f, t, b;
            cin >> f >> t >> b;
            AddLine(f, t, b);
        }
        MaxFlow(Sour, Sink);

        int Ans = 0;
        for(int i=0; i<LineInfo.size(); i++)
            if(CheckEdge(LineInfo[i].first, LineInfo[i].second)) Ans++;
        cout << Ans << "\n";
    }
}

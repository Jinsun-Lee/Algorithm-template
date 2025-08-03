#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

const int INF = 0x3f3f3f3f;
#define X first
#define Y second

const int MX = 1'001;
int d[MX], pre[MX]; 
vector<pair<int, int>> adj[MX]; 

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    int N, M; cin >> N >> M;
    fill(d, d + N + 1, INF);

    while (M--) {
        int u, v, w; cin >> u >> v >> w; 
        adj[u].push_back({ w,v });
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    int st, en; cin >> st >> en;
    d[st] = 0;
    pq.push({ d[st],st }); 

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();  

        if (d[cur.Y] != cur.X) continue;

        for (auto nxt : adj[cur.Y]) {
            if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pre[nxt.Y] = cur.Y; // 추가
            pq.push({ d[nxt.Y],nxt.Y });
        }
    }

    cout << d[en] << "\n";

    string path = to_string(en);
    int cnt;
    for (cnt = 1; en != st; ++cnt) {
        en = pre[en];
        path = to_string(en) + " " + path;
    }
    cout << cnt << "\n";
    cout << path;

    /*
    vector<int> path;
    while (en != st) {
        path.push_back(en);
        en = pre[en];
    }

    path.push_back(en); // st
    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for (int x : path) cout << x << " ";
    */
    return 0;
}
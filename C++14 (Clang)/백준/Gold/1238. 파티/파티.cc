#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define PB push_back
#define X first
#define Y second

typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MX = 1001;
int d[MX];
vector<pii> adj[MX];

int N, M;

int dijstra(int st, int en) {
	fill(d, d + N + 1, INF); // M대신 N으로 
	d[st] = 0;

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({d[st], st});

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();

		if (cur.X != d[cur.Y]) continue;

		for (auto nxt : adj[cur.Y]) {
			if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue; // d[cur.V] 대신 nxt.W
			d[nxt.Y] = d[cur.Y] + nxt.X;
			pq.push({d[nxt.Y], nxt.Y});
		}
	}

	return d[en];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	int en; cin >> en;
	
	int u, v, w;
	for (int i = 0; i < M; ++i) {
		cin >> u >> v >> w;
		adj[u].PB({ w, v });
	}
	
	int ans = 0; 
	for (int st = 1; st <= N; ++st) {
		ans = max(ans, dijstra(st, en)+dijstra(en, st));
	}
	cout << ans;
	
	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

int N, M, A, B;

const int MX = 801;
int d[MX];
vector<pii> adj[200'001];

void INPUT() {
	cin >> N >> M;
	int u, v, w;
	for (int i = 1; i <= M; ++i) {
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
		adj[v].push_back({ w, u });
	}
	cin >> A >> B; // 경유지
}

void dijstra(int st) {
	fill(d, d + N + 1, INF);
	d[st] = 0;

	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push({ d[st], st });

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();

		if (d[cur.Y] != cur.X) continue;

		for (auto nxt : adj[cur.Y]) {
			if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
			d[nxt.Y] = d[cur.Y] + nxt.X;
			pq.push({ d[nxt.Y], nxt.Y });
		}
	}
}

void SOLVE() {
	INPUT();

	dijstra(1);
	int d1A = d[A];
	int d1B = d[B];

	dijstra(A);
	int dAB= d[B];
	int dAN= d[N];

	dijstra(B);
	int dBN = d[N];

	int sum = 0;
	sum = min(INF, d1A + dAB + dBN); // 1 A B N
	sum = min(sum, d1B + dAB + dAN); // 1 B A N
	if (sum >= INF || sum < 0) cout << -1; // 0보다 작을 때
	else cout << sum;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	SOLVE();
	return 0;
}
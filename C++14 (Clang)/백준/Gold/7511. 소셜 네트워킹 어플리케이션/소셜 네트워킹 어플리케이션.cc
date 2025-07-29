#include <iostream>
#include <vector>
using namespace std;

vector<int> p;

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool uni(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return false;
	if (p[v] < p[u]) swap(u, v);
	if (p[u] == p[v]) p[u]--;
	p[v] = u; 
	return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		cout << "Scenario " << t << ":\n";
        
		int n, k, u, v, m;
		cin >> n >> k; // 유저의 수, 친구관계의 수
        
        // 초기화 필수
        p.assign(n+1, -1);
        
		while (k--) {
			cin >> u >> v; // 친구라는 뜻
			uni(u, v);
		}

		cin >> m; // 구할 친구 쌍의 수
		while (m--) {
			cin >> u >> v;
			cout << ((find(u) == find(v)) ? 1 : 0) << "\n";
		}
		cout << "\n";
	}
	return 0;
}
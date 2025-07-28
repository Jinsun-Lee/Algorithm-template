#include <iostream>
#include <vector>
using namespace std;

vector<int> p(1000001, -1);

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]); // 경로 압축도 같이 해
}

bool uni(int u, int v) {
	u = find(u); // int u = find(a);
	v = find(v);
	if (u == v) return false; //이미 같은 그룹
	
	//최적화1. union by rank	
	if (p[v] < p[u]) swap(u, v); // V의 랭크가 더 큼 = 자식이 더 길어서 U>=V의 랭크로 만듦
	if (p[u] == p[v]) p[u]--; // 랭크가 같은 경우 랭크 1 증가(근데 음수라서 빼야 해)
	p[v] = u; // v를 u의 자식으로 만든다
	return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	int q, a, b;
	while (m--) {
		cin >> q >> a >> b;
		if (q == 1) cout << ((find(a) == find(b) ? "YES" : "NO")) << "\n";
		else  uni(a, b);
	}
	return 0;
}
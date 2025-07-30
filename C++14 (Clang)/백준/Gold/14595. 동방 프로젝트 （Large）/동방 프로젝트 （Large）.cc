#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> p; // (1000001, -1);

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

void uni(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	
	if (p[v] < p[u]) swap(u, v);
	if (p[v] == p[u]) --p[u];
	p[v] = u;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    
	cin >> N >> M;
    
    if (M == 0) {
		cout << N << "\n";
		return 0;
	}

	p.assign(N + 1, -1);

	// 사이즈를 M으로 한정해 줘
	vector<pair<int, int>> vec(M); 
	for (int i = 0; i < M; ++i) cin >> vec[i].first >> vec[i].second;

	sort(vec.begin(), vec.end());
	
	int x = vec[0].first, y = vec[0].second;

	// i=1부터 시작
	for (int i = 1; i < M; ++i) { 
		int xx = vec[i].first, yy = vec[i].second;

		if (xx <= y) y = max(y, yy);
		else {
			// 구간 끊기기
			for (int j = x; j < y; ++j) uni(j, j +1);				
			x = xx; y = yy;
		}
	}
	
	// 마지막 구간 union
	for (int j = x; j < y; ++j) uni(j, j + 1);
    
	int cnt = 0;
	for (int i = 1; i <= N; ++i) if (p[i] < 0) ++cnt;
	cout << cnt;
	return 0;
}
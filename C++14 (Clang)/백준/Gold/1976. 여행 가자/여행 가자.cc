#include <iostream>
#include <algorithm>
using namespace std;

const int MX = 201;
int N, M, p[MX];

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

void uni(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;

	if (p[v] < p[u]) swap(u, v); 
	if (p[v] == p[u]) --p[u]; // 주의
	p[v] = u;
	return;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
    
	fill(p, p + MX, -1);

	int tmp; 
	for (int i = 1; i <= N; ++i) { // 범위 주의
		for (int j = 1; j <= N; ++j) {
			cin >> tmp;
			if (tmp) uni(i, j);
		}
	}
	
	// M개 만큼을 돌면서 그룹이 다르면 break 걸고 "NO" 출력
	int grp;
	cin >> tmp;
	grp = find(tmp);

	for (int i = 2; i <= M; ++i) {
		cin >> tmp;
		if (grp != find(tmp)) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}
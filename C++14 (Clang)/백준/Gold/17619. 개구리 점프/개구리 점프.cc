#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pos {
	int x, y, idx;
};

bool cmp(Pos a, Pos b) {
	return a.x < b.x;
}

const int MX = 100'001;
vector<int> p(MX, -1);

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

void uni(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;

	if (p[v] < p[u]) swap(u, v);
	//if (p[v] == p[u]) --p[u];
	p[u] += p[v];
	p[v] = u;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int N, Q; cin >> N >> Q;
	vector<Pos> tree(N+1);

	int a, b, c;
	for (int i = 1; i <= N; ++i) {
		cin >> a >> b >> c;
		tree[i] = { a, b, i };
	}

	sort(tree.begin(), tree.end(), cmp);
	
	int x = tree[0].x, y = tree[0].y;
	for (int i = 1; i <= N; ++i) {
		int xx = tree[i].x, yy = tree[i].y;
		if (xx <= y) {
			uni(tree[i - 1].idx, tree[i].idx);
			y = max(y, yy);
		}
		else y = tree[i].y;
	}

	while (Q--) {
		cin >> a >> b;
		if (find(a) == find(b)) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
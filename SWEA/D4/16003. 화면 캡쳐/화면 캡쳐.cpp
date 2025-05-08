#include <iostream>
#include <algorithm>
using namespace std;

int tCase, n, lim;

void dfs(int cur) {
	if (cur > n || lim==0) return;
	cout << cur << ".png "; lim--;

	for (int i = 0; i < 10; ++i) {
		int nxt = cur * 10 + i;
		if (nxt > n || lim ==0) break;
		dfs(nxt);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> tCase;
	for (int t = 1; t <= tCase; ++t) {
		cin >> n;
		lim = min(50, n);

		cout << "#" << t << " ";
		for (int i = 1; i < 10; ++i) {
			if (i > n || lim == 0) break;
			dfs(i);
		}

		cout << "\n";
	}
	return 0;
}
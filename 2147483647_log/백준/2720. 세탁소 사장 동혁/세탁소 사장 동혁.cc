#include <iostream>
#include <cstring>
using namespace std;

int unit[4] = {25, 10, 5, 1}, cnt[4];

void dfs(int dep, int res) {
	if (res==0) return;

	cnt[dep] = res / unit[dep];
	dfs(dep + 1, res - (cnt[dep]*unit[dep]));
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int tc, c; cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		memset(cnt, 0, sizeof(cnt));
		cin >> c; dfs(0, c);
		for (int i = 0; i < 4; ++i) cout << cnt[i] << " ";
		cout << "\n";
	}
	return 0;
}
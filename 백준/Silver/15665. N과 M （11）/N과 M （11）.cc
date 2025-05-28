#include <iostream>
#include <algorithm>
using namespace std;

int N, M, ans[8], num[8];

void dfs(int depth, int start) {
	if (depth >= M) {
		for (int i = 0; i < M; ++i) cout << ans[i] << " ";
		cout << "\n";
		return;
	}

	int pre = 0;
	for (int i = 0; i < N; ++i) {
		if (pre == num[i]) continue;
		pre = num[i];

		ans[depth] = num[i];
		dfs(depth + 1, i);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) cin >> num[i];
	sort(&num[0], &num[N]);
	dfs(0, 0);
	return 0;
}
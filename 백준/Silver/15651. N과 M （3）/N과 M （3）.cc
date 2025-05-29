#include <iostream>
using namespace std;

int N, M, ans[8];

void dfs(int depth) {
	if (depth >= M) {
		for (int i = 0; i < M; ++i) cout << ans[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; ++i) {
		ans[depth] = i + 1;
		dfs(depth + 1);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	dfs(0);
	return 0;
}
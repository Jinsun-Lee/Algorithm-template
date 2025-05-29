#include <iostream>
#include <algorithm>
using namespace std;

int N, M, ans[8], num[8];
bool used[8];

void dfs(int depth) {
	if (depth >= M) {
		for (int i = 0; i < M; ++i) cout << ans[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; ++i) {
		if (used[i]) continue;
		used[i] = 1;
		ans[depth] = num[i];
		dfs(depth + 1);
		used[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) cin >> num[i];
	sort(&num[0], &num[N]);
	dfs(0);
	return 0;
}
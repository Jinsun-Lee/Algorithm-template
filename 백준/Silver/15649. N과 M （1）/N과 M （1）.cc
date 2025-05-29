#include <iostream>
using namespace std;

int N, M;
bool used[8];

void dfs(int depth, string ans) {
	if (depth >= M) {
		for (char c : ans) cout << c << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; ++i) {
		if (used[i]) continue;
		used[i] = 1;
		ans += i + 1 + '0';
		dfs(depth + 1, ans);
		used[i] = 0;
		ans.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	dfs(0, "");
	return 0;
}
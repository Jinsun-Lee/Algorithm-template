#include <iostream>
#include <algorithm>
using namespace std;

const int MX = 8;
// 5e4, 1e4, 5e3, ..., 1e1은 더블, 웹에서 컴파일 에러, (int)5e4는 길어서
int unit[MX] = { 50000, 10000, 5000, 1000, 500, 100, 50, 10 };
int N, ans[MX]; // 거슬러 주어야 할 금액, 각 종류의 돈의 수

void dfs(int depth, int res) {
	if (res == 0 || depth >= MX) return;

	int carry = res / unit[depth];
	ans[depth] = carry;
	res -= carry * unit[depth];
	dfs(depth + 1, res);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		fill(ans, ans + MX, 0); // 초기화
		cin >> N;

		dfs(0, N); // 현재단위, 남은금액
		cout << "#" << t << "\n";
		for (int i : ans) cout << i << " ";
		cout << "\n";
	}
	return 0;
}
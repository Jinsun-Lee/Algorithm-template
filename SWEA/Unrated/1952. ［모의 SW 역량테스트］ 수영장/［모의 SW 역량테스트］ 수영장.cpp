#include <iostream>
#include <algorithm>
using namespace std;

int pay[4], cnt[15], ans;

void dfs(int month, int sum) {
	if (sum > ans) return;
	if (month >= 12) {
		ans = min(ans, sum);
		return;
	}

	// for으로 12개월 돌리지 않기
	dfs(month + 3, sum+pay[2]); // 3개월
	dfs(month + 1, sum+pay[1]); // 1개월
	dfs(month + 1, sum+pay[0]*cnt[month]); // 1일
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		for (int i = 0; i < 4; ++i) cin >> pay[i];
		for (int i = 0; i < 12; ++i) cin >> cnt[i];
		ans = pay[3]; // 1년치 이용 비용

		dfs(0, 0);
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}

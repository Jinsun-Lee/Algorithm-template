#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	const int unit[8] = { 50000, 10000, 5000, 1000, 500, 100, 50, 10 };

	int tCase; cin >> tCase;
	for (int tc = 1; tc <= tCase; ++tc) {
		
		int N; cin >> N;
		int ans[8] = {}; // 0으로 초기화

		for (int i = 0; i < 8; ++i) { // unit.size() 못 써
			if (N == 0) break;
			if (N < unit[i]) continue;

			ans[i] = N / unit[i];
			N = N - (unit[i] * ans[i]);
		}

		cout << "#" << tc << "\n";
		for (int i : ans) cout << i << " ";
		cout << "\n";
	}
	return 0;
}
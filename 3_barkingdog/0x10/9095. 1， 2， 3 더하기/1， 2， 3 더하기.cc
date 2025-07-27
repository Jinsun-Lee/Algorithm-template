#include <iostream>
using namespace std;

int dp[12] = {0, 1, 2, 4};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	for (int i = 4; i < 11; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	int tc, n; cin >> tc;
	while (tc--) {
		cin >> n;
		cout << dp[n] << "\n";
	}
	return 0;
}
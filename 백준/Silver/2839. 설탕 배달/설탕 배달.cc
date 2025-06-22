#include <iostream>
#include <algorithm>
using namespace std;

int dp[5001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;

	fill(dp, dp + N + 1, 1e9);
	dp[0] = 0;

	for (int i = 3; i <= N; ++i) {
		if (i>=3) dp[i] = min(dp[i], dp[i-3]+1);
		if (i>=5) dp[i] = min(dp[i], dp[i-5]+1);
	}

	cout << (dp[N]>=1e9 ? -1 : dp[N]);
	return 0;
}
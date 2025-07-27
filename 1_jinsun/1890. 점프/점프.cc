#include <iostream>
using namespace std;

const int MX = 101;
int N, map[MX][MX];

typedef long long ll;
ll dp[MX][MX];

void dynamicprogramming() {
	dp[0][0] = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int jump = map[i][j];
			if (jump == 0) continue;
			if (i + jump < N) dp[i + jump][j] += dp[i][j];
			if (j + jump < N) dp[i][j + jump] += dp[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) cin >> map[i][j];
	}

	dynamicprogramming(); 
    cout << dp[N - 1][N - 1];
	return 0;
}
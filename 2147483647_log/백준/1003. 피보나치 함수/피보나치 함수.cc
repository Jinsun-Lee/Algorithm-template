#include <iostream>
using namespace std;

inline void PRINT(const int& a, const int& b) {
	cout << a << ' ' << b << "\n";
}

int dp[41] = { 0,1,1 };

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	for (int i = 3; i <= 40; ++i) {
		dp[i] = dp[i-1] + dp[i-2]; 
	}
	
	int tc; cin >> tc;
	while (tc--) {
		int N; cin >> N;
		
		if (N == 0) PRINT(1, 0);
		else if (N == 1) PRINT(0, 1);
		else PRINT(dp[N - 1], dp[N]); // 0출력횟수+1출력횟수
	}
	return 0;
}
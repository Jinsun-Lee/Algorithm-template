#include <iostream>
using namespace std;

const int MX = 1002;
int dp[MX][MX];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	// 범위 주의
	for(int i = 1; i <=1000; i++){
		dp[i][0]=dp[i][i]=1;

		for(int j = 1; j<i; j++){
			dp[i][j]=(dp[i-1][j]+dp[i-1][j-1]) %10007;
		}
	}

	int N,K;
	cin >> N >> K;
	cout << dp[N][K];

	return 0;
}
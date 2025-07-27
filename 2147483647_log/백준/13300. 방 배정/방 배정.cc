#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int n, k;
	cin >> n >> k;
	
	// stuCnt개의 줄동안 여0남1 학년1~6
	int s, y;
	int cnt[2][7]{ 0 };
	for (int i = 0; i < n; i++) {
		cin >> s >> y;
		cnt[s][y]++;
	}

	int ans = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j < 7; j++) {
			ans += cnt[i][j] / k; // 아...! K가 2일 때로 생각했네 바보다

			// 만약 학생이 남을 경우 방이 하나 더 잇어야 해
			if (cnt[i][j] % k) ans++;
		}
	}
	
	cout << ans;

	return 0;
}
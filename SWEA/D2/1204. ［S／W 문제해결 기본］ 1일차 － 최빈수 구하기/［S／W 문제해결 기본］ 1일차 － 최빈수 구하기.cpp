#include <iostream>
#include <cstring>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int tc; cin >> tc;
	int t, cnt[101];
	while (tc--) {
		memset(cnt, 0, sizeof(cnt));
		cin >> t; cout << "#" << t << " ";
		for (int i = 0; i < 1000; ++i) {
			cin >> t;
			cnt[t]++;
		}

		// 가장 많이 나온 인덱스 찾기
		//cout << *max_element(cnt, cnt + 101) << "\n";
		int maxIdx = 0;
		for (int i = 0; i <= 100; ++i) {
			if (cnt[i] >= cnt[maxIdx]) maxIdx = i; // 등호 추가해야 값 같을 때 큰 수로 갱신됨
		}
		cout << maxIdx << "\n";
		
	}
	return 0;
}
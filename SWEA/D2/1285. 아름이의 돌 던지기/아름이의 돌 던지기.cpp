#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		int N, tmp; cin >> N;

		const int L = 200005;
		int p0 = L, diff = L, cnt = 0;
		bool unique = true;
		
		// 초기 상태일 때
		cin >> tmp;
		if (tmp == 0) {
			p0 = 0;
			unique = false;
		} 
		else {
			diff = abs(tmp);
			cnt++;
		}
		
		// 초기 상태 이후 
		for (int i = 1; i < N; ++i) {
			cin >> tmp;

			// 0이 처음 들어오는 거라면
			if (tmp == 0 && unique) {
				p0 = i;
				unique = false; 
				continue;
			}
			
			tmp = abs(tmp);
			
			// 기존보다 더 가까우면 초기화하고 갱신
			if (tmp < diff) {
				diff = tmp;
				cnt = 0;
			}		

			// 차이가 같다면 추가
			if (tmp == diff) cnt++;
		}

		if (diff == 0) cnt++;

		//for (int d : posDiff) dist += d; // 진짜 대환장 그냥 diff 출력하는 거였어
		cout << "#" << t << " " << diff << " " << cnt << "\n";
	}
	return 0;
}
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int n, t;
	cin >> n;
	
	// -100 <= v && v <= 100 이므로 음수도 저장할 수 있는 공간을 배열에 추가
	int cnt[201]{ 0 };

	for (int i = 0; i < n; i++) {
		cin >> t;
		cnt[t+100]++; // 인덱스에 맞는 값 
	}
	
	int findVal;
	cin >> findVal;
	cout << cnt[findVal+100];

	return 0;
}
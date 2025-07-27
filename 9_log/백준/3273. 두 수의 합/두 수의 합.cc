#include <iostream>

using namespace std;

bool num[2000001]{ 0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int n;
	cin >> n;

	//bool num[2000001]{0};
	
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		num[x] = true;
	}

	int t; // 맞추고자 하는 숫자
	cin >> t;

	int cnt = 0; // 몇 번 등장하는지 카운트
	for (int i = 1; i < (t+1) / 2; ++i) { // n까지가 아니라 (t+1)/2
		if (num[i] && num[t - i]) cnt++;
	}

	cout << cnt;

	return 0;
}
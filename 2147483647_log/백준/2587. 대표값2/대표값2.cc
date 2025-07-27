#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int a[5];
	for (int i = 0; i < 5; i++) cin >> a[i];

	int sum=0;
	for (int i = 0; i < 5; i++) sum+=a[i];
	cout << sum / 5 << "\n"; // 평균

	sort(a, a + 5);
	cout << a[2]; // 중앙값

	return 0;
}
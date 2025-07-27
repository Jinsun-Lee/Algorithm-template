#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int n;
	cin >> n;

	// 1 2 3 4 붙이고 아래의 for문에서 첫 줄만 제거, 그리고 범위 변경
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) cout << "*";
		for (int k = 1; k <= 2 * (n - i); k++) cout << " ";
		for (int j = 1; j <= i; j++) cout << "*";
		cout << "\n";
	}
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n - i; k++) cout << "*";
		for (int k = 1; k <= 2 * i; k++) cout << " ";
		for (int j = 1; j <= n - i; j++) cout << "*";
		cout << "\n";
	}

	return 0;
}
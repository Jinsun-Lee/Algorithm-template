#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int n;
	cin >> n;

    for (int i = 0; i < n; i++) {
		for (int k = 0; k < n - i - 1; k++) cout << " "; 
		for (int j = 0; j <= i; j++) cout << "*";
		for (int l = 0; l < i; l++) cout << "*"; // 2번에 추가 출력
		cout << "\n";
	}

	return 0;
}
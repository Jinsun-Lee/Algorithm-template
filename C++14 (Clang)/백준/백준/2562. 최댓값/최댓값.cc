#include <iostream>

using namespace std;

int n, maxNum, maxIndex;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	
	for (int i = 1; i <= 9; i++) {
		cin >> n;

		if (maxNum < n) {
			maxNum = n;
			maxIndex = i;
		}
	}

	cout << maxNum << "\n" << maxIndex;

	return 0;
}
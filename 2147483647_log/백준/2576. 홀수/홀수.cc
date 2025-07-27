#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int tmp, minNum=101, sum = 0;
	for (int i = 0; i < 7; i++) {
		cin >> tmp;
		if (tmp % 2 == 1) {
			sum += tmp;
			minNum = min(minNum, tmp);
		}
	}

	if (sum == 0) cout << "-1";
	else {
		cout << sum << "\n";
		cout << minNum;
	}

	return 0;
}
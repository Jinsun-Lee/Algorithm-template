#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int tCase;
	cin >> tCase;

	int tmp, ans;
	for (int i = 1; i <= tCase; i++) {
		tmp = 0, ans = 0;
		for (int j = 0; j < 10;j++) {
			cin >> tmp;
			if (tmp % 2 != 0) ans += tmp;
		}
		cout << "#" << i << " " << ans << "\n";
	}

	return 0;
}
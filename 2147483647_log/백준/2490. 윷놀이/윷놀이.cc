#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int a, b, c, d;
	string res = "DCBAE";

	for (int i = 0; i < 3; i++) {
		cin >> a >> b >> c >> d;

		cout << res[a + b + c + d] << "\n";
	}

	return 0;
}
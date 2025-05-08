#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int tCase, tmp, sum; cin >> tCase;
	for (int t = 1; t <= tCase; ++t) {
		sum = 0;
		for (int i = 0; i < 10; ++i) {
			cin >> tmp;
			sum += tmp;
		}

		// round(sum/10)이 아님 주의
		cout << "#" << t << " " << round(sum/10.0) << "\n";
	}
	return 0;
}
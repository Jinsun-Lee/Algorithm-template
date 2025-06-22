#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int N;
	long long total;
	int unit[11];

	cin >> N >> total;
	for (int i = 0; i < N; ++i) cin >> unit[i];
	reverse(unit, unit + N);

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		if (unit[i] <= total) {
			ans += total / unit[i];
			total %= unit[i];
		}
	}
	cout << ans;
	return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int arr[1005];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int N, cnt, diff;
	for (int t = 1; t <= 10; ++t) {
		
		cin >> N;
		cnt = 0;
		for (int i = 0; i < N; ++i) cin >> arr[i];

		for (int i = 2; i < N-2; ++i) {
			diff = max({arr[i-2], arr[i-1], arr[i+1], arr[i+2]});
			if (arr[i] > diff) cnt += arr[i] - diff;
		}

		cout << "#" << t << " " << cnt << "\n";
	}
	return 0;
}
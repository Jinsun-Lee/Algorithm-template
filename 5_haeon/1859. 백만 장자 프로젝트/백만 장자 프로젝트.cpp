#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    
	int tc; cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		int N; cin >> N;

		vector<int> price(N);
		for (int i = 0; i < N; ++i) cin >> price[i];

		long long profit = 0;
		int maxPrice = 0;

		// 뒤에서부터 탐색
		for (int i = N-1; i >= 0; --i){
			if (price[i] > maxPrice) maxPrice = price[i];
			else profit += (maxPrice - price[i]);
		}

		cout << "#" << t << " " << profit << "\n";
	}
	return 0;
}
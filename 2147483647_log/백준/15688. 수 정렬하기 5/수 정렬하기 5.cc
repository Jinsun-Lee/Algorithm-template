#include <iostream>
using namespace std;
#define FASTIO cin.tie(0)->sync_with_stdio(0)

int cnt[2000001];

int main() {
	FASTIO;
	int N, tmp; cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		cnt[1000000 + tmp]++;
	}

	for (int i = 0; i <= 2000000; ++i) {
		while (cnt[i]--) cout << i - 1000000 << "\n";
	}
	return 0;
}
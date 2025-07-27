#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO cin.tie(0)->sync_with_stdio(0)

int N, ans[10000];

int main() {
	FASTIO;

	cin >> N;
	for (int i = 0; i < N; ++i) cin >> ans[i];

	if (prev_permutation(ans, ans + N)) {
		for (int i = 0; i < N; ++i) cout << ans[i] << " ";
	}
	else cout << -1;

	return 0;
}
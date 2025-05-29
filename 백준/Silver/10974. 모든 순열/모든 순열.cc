#include <iostream>
#include <vector>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
	fastio;

	int N; cin >> N;
	int num[8] = {1, 2, 3, 4, 5, 6, 7, 8};

	do {
		for (int i = 0; i < N; ++i) cout << num[i] << " ";
		cout << "\n";
	} while (next_permutation(&num[0], &num[N]));
	return 0;
}
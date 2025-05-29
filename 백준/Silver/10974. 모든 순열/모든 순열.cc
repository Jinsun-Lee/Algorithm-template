#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
int main() {
	fastio;
    
	int N; cin >> N;
	vector<int> num(N);
	iota(num.begin(), num.end(), 1);

	do {
		for (auto& i : num) cout << i << " ";
		cout << "\n";
	} while (next_permutation(num.begin(), num.end()));
	return 0;
}
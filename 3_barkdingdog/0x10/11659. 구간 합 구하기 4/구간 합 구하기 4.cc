#include <iostream>
using namespace std;

int n, m, psum[100001], a, b;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> psum[i];
		psum[i] += psum[i - 1];
	}
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		cout << psum[b] - psum[a - 1] << "\n";
	}
    
	return 0;
}
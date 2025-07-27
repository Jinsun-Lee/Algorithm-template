#include <iostream>

using namespace std;

int funZ(int n, int r, int c) {
	if (n == 0) return 0;
	int half = 1<<(n-1); // (1 << n) - 1;

	if (r < half && c < half) return funZ(n - 1, r, c);
	if (r < half && c >= half) return funZ(n - 1, r, c - half) + half * half;
	if (r >= half && c < half) return funZ(n - 1, r - half, c) + 2 * half * half;
	return funZ(n - 1, r - half, c - half) + 3 * half * half;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int n, r, c;
	cin >> n >> r >> c;
	cout << funZ(n, r, c);
	return 0;
}
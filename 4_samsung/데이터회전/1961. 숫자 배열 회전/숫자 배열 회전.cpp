#include <iostream>
using namespace std;

const int MX = 7;
int N, map[MX][MX], r90[MX][MX], r180[MX][MX], r270[MX][MX];

void rotate(int src[MX][MX], int dst[MX][MX]) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			dst[j][N - i - 1] = src[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int tCase; cin >> tCase;
	for (int t = 1; t <= tCase; ++t) {
		cin >> N;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) cin >> map[i][j];
		}

		rotate(map, r90);
		rotate(r90, r180);
		rotate(r180, r270);

		cout << "#" << t << "\n";
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) cout << r90[i][j]; // 741
			cout << ' ';
			for (int j = 0; j < N; ++j) cout << r180[i][j]; // 987
			cout << ' ';
			for (int j = 0; j < N; ++j) cout << r270[i][j]; // 369
			cout << '\n';
		}
	}
	return 0;
}
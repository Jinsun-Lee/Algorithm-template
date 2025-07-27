#include <iostream>
using namespace std;

const int MX = 101;
bool map[MX][MX];

void update(int sy, int sx, int ey, int ex) {
	for (int y = sy; y < ey; ++y) {
		for (int x = sx; x < ex; ++x) {
			map[y][x] = 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	for (int i = 0; i < 4; ++i) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		update(a, b, c, d);
	}
	
	int cnt = 0;
	for (int i = 0; i < MX; ++i) {
		for (int j = 0; j < MX; ++j) {
			if (map[i][j] == 1) cnt++;
		}
	}
	cout << cnt;
	return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

const int dy[4] = {0,1,0,-1}, dx[4] = {1,0,-1,0}; // 우하좌상
const int MX = 10;
int N, map[MX][MX];

void print() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) cout << map[i][j] << " ";
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		cin >> N;
		fill(&map[0][0], &map[MX-1][MX], 0);

		int y = 0, x = 0, dir = 0;
		for (int i = 1; i <= N * N; ++i) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if (ny >= N || nx >= N || ny < 0 || nx < 0 || map[ny][nx] > 0) {
				dir = (dir + 1) % 4;
				ny = y + dy[dir];
				nx = x + dx[dir];
			}

			map[y][x] = i;
			y = ny, x = nx;
		}

		cout << "#" << t << "\n";
		print();
	}
	return 0;
}
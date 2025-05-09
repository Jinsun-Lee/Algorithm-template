#include <iostream>
using namespace std;

const int MX = 1001;
int N, G, map[MX][MX]; 
int dy[] = {1, 0, -1, 0}, dx[] = {0, 1, 0, -1};
int dir, y, x, gY, gX;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> G;

	// 값 채우기
	for (int i = N * N; i > 0; --i) {
		map[y][x] = i;
        
        // 값이 내가 찾고자 했건 거면
		if (i == G) { gY = y + 1; gX = x + 1; }
		
		/* 방법1
		if (y + dy[dir] >= N || x + dx[dir] >= N || y + dy[dir] < 0 || x + dx[dir] < 0 || map[y + dy[dir]][x + dx[dir]] != 0) { // 이미 값 넣음
			dir = (dir + 1) % 4;
		}
		y = y + dy[dir]; x = x + dx[dir];
		*/
		
		// 방법2
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny < 0 || ny >= N || nx < 0 || nx >= N || map[ny][nx] != 0) {
			dir = (dir + 1) % 4;
			ny = y + dy[dir]; // ny, nx 쓸 거면 이거 추가
			nx = x + dx[dir];
		}
		y = ny; x = nx;
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0;j < N; ++j) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << gY << " " << gX;
	return 0;
}
#include <iostream>
using namespace std;

int M, N;
bool map[101][101];
int dy[] = {0, 1, 0,-1}, dx[] = {1, 0, -1, 0}; // 순서 주의
int dir, y, x, ny, nx, cnt;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> M >> N;
	for (int i = 0; i < M * N; ++i) { // M*N번 동작하게
		map[y][x] = 1; // 주의

		ny=y+dy[dir];
		nx=x+dx[dir];

		// map도 주의, 입력을 5 3이랑 3 5 넣어서 확인
		if (ny >= M || nx >= N || ny < 0 || nx < 0 || map[ny][nx]) {
			dir = (dir + 1) % 4;
			ny = y + dy[dir];
			nx = x + dx[dir];
			if (map[ny][nx]) break; // 끝에 도달했을 때 고려
			cnt++;
		}
		y = ny, x = nx;
	}
    
	cout << cnt;
	return 0;
}

#include <iostream>
using namespace std;

int r, c;
const int MX = 21;
char map[MX][MX];
bool used[26]; // 알파벳 썼는지

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int ans = 0;

void dfs(int y, int x, int cnt) {
	ans = max(ans, cnt); // 최대 이동 거리 갱신

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
		if (used[map[ny][nx] - 'A']) continue; // 이미 사용한 알파벳이면 이동 불가

		used[map[ny][nx] - 'A'] = true;
		dfs(ny, nx, cnt + 1);
		used[map[ny][nx] - 'A'] = false; // 백트래킹
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
		
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}

	
	used[map[0][0] - 'A'] = true;
	dfs(0, 0, 1);

	cout << ans;

	return 0;
}
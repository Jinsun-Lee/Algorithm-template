#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define Y first
#define X second 

using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

queue<pair<int, int>> q;

int n;

const int MX = 102;
int map[MX][MX];
bool visited[MX][MX];

int maxCnt = 0, maxLimit = 0;

void bfs(int y, int x, int limit) { //
	q.push({ y, x });
	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

			if (!visited[ny][nx] && map[ny][nx] > limit) { // 
				visited[ny][nx] = true;
				q.push({ ny, nx });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			maxLimit = max(maxLimit, map[i][j]); // 잠기는 최대 높이
		}
	}

	for (int limit = 0; limit <= maxLimit; limit++) { // 
		
		for (int i = 0; i < n; i++) fill(visited[i], visited[i] + n, false); // 초기화 필요

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] > limit && !visited[i][j]) {
					visited[i][j] = true;
					bfs(i, j, limit);
					cnt++;
				}
			}
		}

		maxCnt = max(cnt, maxCnt);

	}

	cout << maxCnt << "\n";

	return 0;
}
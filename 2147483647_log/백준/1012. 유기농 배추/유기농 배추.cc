#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define Y first
#define X second 

using namespace std;

int m, n, k;
const int MX = 52;
int map[MX][MX];
bool visited[MX][MX];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

queue<pair<int, int>> q;

void bfs(int y, int x) {
	q.push({ y, x });

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

			if (map[ny][nx] == 1 && !visited[ny][nx]) {
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

	int tCase;
	cin >> tCase;

	while (tCase--) {
		cin >> m >> n >> k;

		for (int i = 0; i < n; i++) { // 초기화 꼭 해
			fill(map[i], map[i] + m, 0); 
			fill(visited[i], visited[i] + m, false);
		}
		
		int x, y;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			map[y][x] = 1;
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j]==1 && !visited[i][j]) { 
					visited[i][j] = true;
					bfs(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}
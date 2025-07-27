#include <iostream>
#include <queue>

#define Y first
#define X second 

using namespace std;

int n;

const int MX = 302;
int dist[MX][MX];

queue<pair<int, int>> q;

int dy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int tCase;
	cin >> tCase;
	while (tCase--) {
		cin >> n;

		for (int i = 0; i < n; i++) {
			fill(dist[i], dist[i] + n, -1);
		}

		int y, x; // 나이트가 현재 있는 칸
		cin >> y >> x;
		q.push({ y, x });
		dist[y][x] = 0;

		int ty, tx; // 나이트가 이동하려고 하는 칸
		cin >> ty >> tx;

		while (!q.empty()) {
			auto cur = q.front();
			q.pop();

			for (int i = 0; i < 8; i++) {
				int ny = cur.Y + dy[i];
				int nx = cur.X + dx[i];

				// 뭐지 왜 안 되는 거지
				//if (ny < 0 || nx < 0 || ny >= ty || nx >= tx) continue; 
				if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
				if (dist[ny][nx] >=0) continue;
				dist[ny][nx] = dist[cur.Y][cur.X] + 1;

				q.push({ ny, nx });
			}
		}

		cout << dist[ty][tx] << "\n";

	}

	return 0;
}
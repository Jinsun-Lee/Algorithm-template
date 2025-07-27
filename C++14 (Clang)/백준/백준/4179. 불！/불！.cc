#include <iostream>
#include <queue>

#define Y first
#define X second 

using namespace std;

int r, c;

const int MX = 1002;
char map[MX][MX];
int dist1[MX][MX]; // 불
int dist2[MX][MX]; // 지훈

queue<pair<int, int>> q1;
queue<pair<int, int>> q2;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> r >> c;

	for (int i = 0; i < r; i++) fill(dist1[i], dist1[i] + c, -1);
	for (int i = 0; i < r; i++) fill(dist2[i], dist2[i] + c, -1);

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];

			if (map[i][j] == 'F') {
				q1.push({ i, j });
				dist1[i][j] = 0;
			}

			if (map[i][j] == 'J') {
				q2.push({ i, j });
				dist2[i][j] = 0;
			}
		}
	}

	while (!q1.empty()) {
		pair<int, int> cur = q1.front(); q1.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;

			if (dist1[ny][nx] >= 0 || map[ny][nx] == '#') continue; 
			dist1[ny][nx] = dist1[cur.Y][cur.X] + 1;
			q1.push({ ny, nx });
		}
	}

	while (!q2.empty()) {
		pair<int, int> cur = q2.front(); q2.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c) {
				cout << dist2[cur.Y][cur.X] + 1;
				return 0; // 벗어났기 때문에 탈출한 것
			}

			//if (dist2[ny][nx] >= 0 || map[ny][nx] != '.') continue;
			if (dist2[ny][nx] >= 0 || map[ny][nx] == '#') continue;
			if (dist1[ny][nx] == -1 || dist1[ny][nx] > dist2[cur.Y][cur.X] + 1) {
				// 불이 아직 방문하지 않았거나, 불보다 숫자가 작을 때라면 
				dist2[ny][nx] = dist2[cur.Y][cur.X] + 1;
				q2.push({ ny, nx });
			}
		}
	}

	cout << "IMPOSSIBLE";

	return 0;
}
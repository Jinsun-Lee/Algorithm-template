#include <iostream>
#include <queue>

#define Y first
#define X second 

using namespace std;

int w, h;

const int MX = 1002;
int map[MX][MX];
int dist1[MX][MX]; // 불
int dist2[MX][MX]; // 사람

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int tCase;
	cin >> tCase;

	while (tCase--) {
		cin >> w >> h;

		for (int i = 0; i < h; i++) {
			fill(dist1[i], dist1[i] + w, 0); // 0으로 초기화
			fill(dist2[i], dist2[i] + w, 0); 
		}

		queue<pair<int, int>> q1 = {}, q2 = {}; // 이렇게 초기화

		char c;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> c;

				if (c == '#') map[i][j] = -1; // 벽일 땐 -1
				else {

					if (c == '*') { // 불의 시작 위치
						q1.push({ i, j });
						dist1[i][j] = 1; // 시작을 1로
					}

					else if (c == '@') { // 상근이의 시작 위치
						q2.push({ i, j });
						dist2[i][j] = 1;
					}

					map[i][j] = 0; // 벽이 아닐 땐 map을 0으로
				}
			}
		}

		while (!q1.empty()) {
			pair<int, int> cur = q1.front(); q1.pop();
			for (int i = 0; i < 4; i++) {
				int ny = cur.Y + dy[i];
				int nx = cur.X + dx[i];

				if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
				if (map[ny][nx] == -1) continue; // 벽일 땐 그만해
				if (dist1[ny][nx]) continue; // 초기 상태일 때에는
				dist1[ny][nx] = dist1[cur.Y][cur.X] + 1;
				q1.push({ ny, nx });
			}
		}

		bool escape = false;
		while (!q2.empty() && escape==false) { // 탈출이 끝나지 않았을 때만 반복
			pair<int, int> cur = q2.front(); q2.pop();
			for (int i = 0; i < 4; i++) {
				int ny = cur.Y + dy[i];
				int nx = cur.X + dx[i];

				if (ny < 0 || nx < 0 || ny >= h || nx >= w) {
					cout << dist2[cur.Y][cur.X] << "\n";
					escape = true;
					break;
				}

				if (map[ny][nx] == -1) continue;
				if (dist2[ny][nx]) continue;
				// 불이 방문했거나
				if (dist1[ny][nx] != 0 && dist1[ny][nx] <= dist2[cur.Y][cur.X] + 1) continue;
				dist2[ny][nx] = dist2[cur.Y][cur.X] + 1;
				q2.push({ ny, nx });
			}
		}
		
		if (escape==false) cout << "IMPOSSIBLE\n";
	}
	
	return 0;
}
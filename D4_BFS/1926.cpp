#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define Y first
#define X second 

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

const int MX = 502;

int n, m;
bool map[MX][MX];
bool visited[MX][MX];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> map[i][j];
	}

	int cnt = 0; // 그림의 수
	int mxArea = 0; // 최대 넓이

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j]==1 && visited[i][j]==false) {
				visited[i][j] = true;
				cnt++;

				queue<pair<int, int>> q;
				q.push({ i, j });

				int area = 0; // 그림의 넓이
                
				while (!q.empty()) {
					pair<int, int> cur = q.front(); q.pop();

					area++; // 연결된 그림으로 판단해서 넓이 증가

					for (int i = 0; i < 4; i++) {
						int ny = cur.Y + dy[i];
						int nx = cur.X + dx[i];

						if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
						if (map[ny][nx] == 1 && visited[ny][nx] == false) {
							visited[ny][nx] = true;
							q.push({ ny, nx });
						}
					}
				}

				//(i, j)를 시작점으로 하는 BFS가 종료됨
				mxArea = max(mxArea, area);
			}
		}
	}

	cout << cnt << "\n" << mxArea;

	return 0;
}

#include <iostream>
#include <queue>

using namespace std;

int L, R, C; // 층수, 행, 열

const int MX = 32;
int map[MX][MX][MX]; 
int dist[MX][MX][MX];

int dz[] = { 0, 0, 0, 0, -1, 1 };
int dy[] = { -1, 0, 1, 0, 0, 0 };
int dx[] = { 0, 1, 0, -1, 0, 0 };

struct Node {
	int z, y, x;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen_s(new FILE*, "input.txt", "r", stdin);

	while (1) {
		cin >> L >> R >> C;

		if (L == 0 && R == 0 && C == 0) break;

		queue<Node> q;

		char c;
		for (int k = 0; k < L; k++) {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					cin >> c;

					map[k][i][j] = 1; // 벽이 아니면 다 지나갈 수 있어
					dist[k][i][j] = 0;  // 초기화, 0은 못 가

					if (c == '#') map[k][i][j] = 0; // 벽은 못 가
					else {
						dist[k][i][j] = -1;

						if (c == 'S') {
							q.push({ k, i, j });
							dist[k][i][j] = 0;
						}

						else if (c == 'E') map[k][i][j] = -1; // 도착 지점은 -1

					}
				}
			}
		}

		bool escape = false;
		while (!q.empty()) {
			if (escape) break;

			Node cur = q.front();
			q.pop();

			for (int i = 0; i < 6; i++) {
				int nz = cur.z + dz[i];
				int ny = cur.y + dy[i];
				int nx = cur.x + dx[i];

				if (nz < 0 || ny < 0 || nx < 0 || nz >= L || ny >= R || nx >= C) continue;
				if (map[nz][ny][nx] == 0 || dist[nz][ny][nx] > 0) continue; // 벽이거나 이미 방문했다면 ㄴ  
				
				dist[nz][ny][nx] = dist[cur.z][cur.y][cur.x] + 1;
				if (map[nz][ny][nx] == -1) { // 도착 지점이면
					cout << "Escaped in " << dist[nz][ny][nx] << " minute(s).\n";
					escape = true;
					break;
				}

				q.push({ nz, ny, nx });
			}
		}

		if (!escape) cout << "Trapped!\n";
	}
		
	return 0;
}
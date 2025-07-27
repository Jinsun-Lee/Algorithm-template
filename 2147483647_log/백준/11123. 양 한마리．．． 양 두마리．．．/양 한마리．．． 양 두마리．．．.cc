#include <iostream>
#include <queue>

using namespace std;

int tCase, h, w;

const int MX = 102;
char map[MX][MX];
bool visited[MX][MX];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

struct Node {
	int y;
	int x;
};

void bfs(int y, int x) {
	queue<Node> q;
	q.push({ y, x });

	while (!q.empty()) {
		Node curr = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = curr.y + dy[i];
			int nx = curr.x + dx[i];

			if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
			if (map[ny][nx]=='#' && visited[ny][nx] == false) {
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

	cin >> tCase;
	while (tCase--) {
		cin >> h >> w;

		string str;
		for (int i = 0; i < h; i++) {
			cin >> str;
			for (int j = 0; j < w; j++) {
				map[i][j] = str[j];
			}
			fill(visited[i], visited[i] + w, false);
		}

		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == '#' && visited[i][j] == false) {
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
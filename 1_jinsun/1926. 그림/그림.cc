#include <iostream>
#include <queue>

using namespace std;

int n, m;
int map[500][500];
bool visited[500][500];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int mxArea = 0;

struct Node {
	int y;
	int x;
};

void bfs(int y, int x) {
	queue<Node> q;
	q.push({ y, x });

	int area = 1; // 주의

	while (!q.empty()) {
		Node curr = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = curr.y + dy[i];
			int nx = curr.x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (map[ny][nx] == 1 && visited[ny][nx] == false) {
				visited[ny][nx] = true;
				area++;
				q.push({ ny, nx });
			}
		}
	}

	if (mxArea < area) mxArea = area;

}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && visited[i][j] == false) {
				visited[i][j] = true;
				bfs(i, j);
				cnt++;
			}
		}
	}

	cout << cnt << "\n";
	if (cnt == 0) cout << "0";
	else cout << mxArea;

	return 0;
}
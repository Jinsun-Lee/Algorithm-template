#include <iostream>
#include <queue>

using namespace std;

int h, w;
const int MX = 1001;
int map[MX][MX];
bool visited[MX][MX];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

struct Node {
	int y, x;
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
			if (map[ny][nx] == 0 && visited[ny][nx] == false) { // 흰색은 0
				visited[ny][nx] = true;
				q.push({ ny, nx });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> h >> w;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			char c;
			cin >> c;
			map[i][j] = c - '0'; //
		}
	}

	for (int j = 0; j < w; j++) {
		if (map[0][j] == 0 && visited[0][j] == false) {
			visited[0][j] = true;
			bfs(0, j);
		}
	}

	for (int j = 0; j < w; j++) {
		//if (map[h-1][j] == 0 && visited[h-1][j]) {
		if (visited[h-1][j]) {
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";

	return 0;
}
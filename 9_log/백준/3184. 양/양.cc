#include <iostream>
#include <queue>

using namespace std;

int r, c;

const int MX = 252;
char map[MX][MX];
bool visited[MX][MX];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int lambF = 0, wolfF = 0;

struct Node {
	int y;
	int x;
};

void bfs(int y, int x) {
	queue<Node> q;
	q.push({ y, x });

	int lamb = 0, wolf = 0;
	if (map[y][x] == 'o') lamb++;
	else if (map[y][x] == 'v') wolf++;

	while (!q.empty()) {
		Node curr = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = curr.y + dy[i];
			int nx = curr.x + dx[i];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if (map[ny][nx]!='#' && visited[ny][nx] == false) {
				if (map[ny][nx] == 'o') lamb++;
				else if (map[ny][nx] == 'v') wolf++;

				visited[ny][nx] = true;
				q.push({ ny, nx });
			}
		}
	}

	if (lamb > wolf) lambF += lamb;
	else wolfF += wolf;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> r >> c;

	string str;
	for (int i = 0; i < r; i++) {
		cin >> str;
		for (int j = 0; j < c; j++) {
			map[i][j] = str[j];
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] != '#' && visited[i][j] == false) {
				visited[i][j] = true;
				bfs(i, j);
			}
		}
	}

	cout << lambF << " " << wolfF;

	return 0;
}
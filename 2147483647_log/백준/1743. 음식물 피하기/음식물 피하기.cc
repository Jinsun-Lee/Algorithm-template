#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k;

int map[100][100];
bool visited[100][100];
vector<int> ans;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

struct Node {
	int y;
	int x;
};

void bfs(int y, int x) {
	queue<Node> q;
	q.push({y, x});

	int cnt = 1;

	while (!q.empty()) {
		Node curr = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = curr.y + dy[i];
			int nx = curr.x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (map[ny][nx] == 1 && visited[ny][nx] == false) {
				visited[ny][nx] = true;
				cnt++;
				q.push({ ny, nx });
			}
		}
	}
	ans.push_back(cnt);
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> n >> m >> k;

	int y, x;
	for (int i = 0; i < k; i++) {
		cin >> y >> x;
		y = y - 1; x = x - 1; //좌표 시작 위치 주의해야 해
		map[y][x] = 1;
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && visited[i][j] == false) {
				visited[i][j] = true;
				bfs(i, j);
			}
		}
	}

	cout << *max_element(ans.begin(), ans.end());
	//for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";

	return 0;
}
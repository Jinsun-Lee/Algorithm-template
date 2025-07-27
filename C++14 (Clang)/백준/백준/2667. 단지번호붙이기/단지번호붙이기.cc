#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int map[25][25];
bool visited[25][25];
vector<int> ans;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

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

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (map[ny][nx] == 1 && visited[ny][nx] == false) {
				visited[ny][nx] = true;
				area++;
				q.push({ ny, nx });
			}
		}
	}

	ans.push_back(area);

}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			char input = cin.get(); //
			while (input == '\n') input = cin.get(); //
			map[i][j] = (int)(input-'0'); //

		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && visited[i][j] == false) {
				visited[i][j] = true;
				bfs(i, j);
				cnt++;
			}
		}
	}

	cout << cnt << "\n";
	sort(ans.begin(), ans.end());
	for (auto i : ans) cout << i << "\n";

	return 0;
}
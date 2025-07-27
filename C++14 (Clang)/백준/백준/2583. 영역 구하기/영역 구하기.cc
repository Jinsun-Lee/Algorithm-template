#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int m, n, k;

int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };

vector<vector<int>> map;
vector<vector<bool>> visited;
vector<int> ans;

struct Node {
	int y;
	int x;
};

void bfs(int y, int x) {
	int num = 1;
	queue<Node> q;
	q.push({ y, x });

	while (!q.empty()) {
		Node curr = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = curr.y + dy[i];
			int nx = curr.x + dx[i];

			if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
			if (map[ny][nx] == 0 && visited[ny][nx] == false) {
				visited[ny][nx] = true;
				num++;
				q.push({ny, nx});
			}
		}
	}
	
	ans.push_back(num);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> m >> n >> k;

	map = vector<vector<int>>(m, vector<int>(n,0));
	visited = vector<vector<bool>>(m, vector<bool>(n, false));

	int x1, y1, x2, y2;
	
	for (int i = 0; i < k; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		
		for (int i = x1; i < x2; i++) { //
			for (int j = y1; j < y2; j++) { // 
				map[j][i] = 1; //
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0 && visited[i][j] == false) {
				visited[i][j] = true;
				bfs(i, j);
				cnt++;
			}
		}
	}

	cout << cnt << "\n";

	sort(ans.begin(), ans.end());
	for (auto c : ans) cout << c << " ";
	//for (int i = 0; i < ans.size();i++) cout << ans[i] << " ";

	return 0;
}
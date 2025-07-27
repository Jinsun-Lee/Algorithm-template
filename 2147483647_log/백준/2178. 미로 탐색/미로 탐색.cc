#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MX =100;
int n, m;
string map[MX]; // 메모리 초과로
int dist[MX][MX];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

struct Node {
	int y;
	int x;
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> n >> m;
	for (int i = 0; i < n; i++) { // 메모리 초과로
		cin >> map[i];
	}

	//for (int i = 0; i < n; i++) fill(dist[i], dist[i] + m, -1); // 메모리 초과로 INT_MAX 못 씀

	queue<Node> q;
	q.push({ 0, 0 });
	dist[0][0] = 1;

	while (!q.empty()) {
		Node curr = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = curr.y + dy[i];
			int nx = curr.x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (map[ny][nx] == '0') continue;
			
			if (dist[ny][nx]) continue; // 메모리 초과로
			dist[ny][nx] = dist[curr.y][curr.x] + 1;
			q.push({ ny, nx });
		}
	}

	cout << dist[n - 1][m - 1];

	return 0;
}
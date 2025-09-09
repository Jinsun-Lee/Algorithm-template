#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MX = 300;

const int dy[] = {-1, 0, 1, 0 }; 
const int dx[] = {0, 1, 0, -1};

int N, M, map[MX][MX];
bool vis[MX][MX];

struct Node { int y, x; };
vector<Node> ice;

int cnt = 0;
int melt = 0;

void solve() {
	for (auto& v : ice){
		int y = v.y;
		int x = v.x;
		if (!map[y][x]) continue;
		
		vis[y][x] = true;

		int sea = 0;
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (vis[ny][nx]) continue;
			if (!map[ny][nx]) ++sea;
		}

		if (map[y][x] - sea <= 0) {
			map[y][x] = 0;
			++melt;
		}
		else map[y][x] -= sea;
	}

	memset(vis, 0, sizeof(vis));
}

bool check_divide() {
	queue<Node> q;

	for (auto& v : ice) {
		int y = v.y;
		int x = v.x;
		if (!map[y][x]) continue;

		else {
			q.push({ y, x });
			vis[y][x] = 1;
			break;
		}
	}

	int connected = 0;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		++connected;

		for (int i = 0; i < 4; ++i) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (vis[ny][nx]) continue;
			if (map[ny][nx]) {
				vis[ny][nx] = 1;
				q.push({ ny, nx });
			}
		}
	}

	memset(vis, 0, sizeof(vis));
	if (connected == ice.size() - melt) return false;
	return true;
}

bool check_end() {
	for (auto& v : ice) {
		int y = v.y;
		int x = v.x;
		if (map[y][x]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
			if (map[i][j]) ice.push_back({i, j});
		}
	}

	while(1) {
		solve();
		++cnt;

		if (check_divide()) {
			cout << cnt;
			return 0;
		}

		if (check_end()) {
			cout << 0;
			return 0;
		}
	}
	return 0;
}

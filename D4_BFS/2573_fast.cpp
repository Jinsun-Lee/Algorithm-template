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

void solve() {
	vector<pair<Node, int>> updates; 

	for (auto& v : ice){
		int y = v.y;
		int x = v.x;
		if (!map[y][x]) continue;

		int sea = 0;
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (map[ny][nx]==0) ++sea;
		}

		int newH = max(0, map[y][x] - sea);
		updates.push_back({ {y, x}, newH });
	}

	// 한꺼번에 갱신
	vector<Node> nextIce;
	for (auto& u : updates) {
		map[u.first.y][u.first.x] = u.second;
		if (u.second > 0) nextIce.push_back({ u.first.y, u.first.x }); // 높이 h가 0 이상일 때 반영해 줌
	}

	ice.swap(nextIce);
}

bool check_divide() {
	if (ice.empty()) return false; // 이미 다 녹음

	memset(vis, 0, sizeof(vis));

	queue<Node> q;
	q.push(ice[0]);
	vis[ice[0].y][ice[0].x] = true;

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

	return connected < (int)ice.size(); // 빙산이 두 덩어리 이상으로 나뉨
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

		if (ice.empty()) {
			cout << 0;
			return 0;
		}
	}
	return 0;
}

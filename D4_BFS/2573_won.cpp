#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MX = 300;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int N, M, map[MX][MX], tmp[MX][MX];
bool vis[MX][MX];

struct Node { int y, x; };
vector<Node> ice;

bool isEmpty = false;

void solve() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
            
			if (map[i][j]) { // 얼음이 없는 것 패스
				for (int d = 0; d < 4; ++d) {
					int ny = i + dy[d];
					int nx = j + dx[d];

					if (ny >= N || nx >= M || ny < 0 || nx < 0) continue;
					if (map[ny][nx] == 0) ++tmp[i][j]; // 인접한 칸이 0이 되면 나중에 적용하게
				}
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) map[i][j] = max(0, map[i][j] - tmp[i][j]);
	}
}

void BFS(int y, int x) {
	vis[y][x] = true;

	queue<pair<int, int>> q;
	q.push({ y, x });

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];

			if (ny >= N || nx >= M || ny < 0 || nx < 0) continue;
			if (vis[ny][nx] || map[ny][nx] == 0) continue;
			vis[ny][nx] = true;
			q.push({ ny, nx });
		}
	}
}

bool check() { // 연결 요소 개수 확인
	memset(vis, 0, sizeof(vis));

	int connected = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {

			if (map[i][j] && vis[i][j] == false) {
				BFS(i, j);
				++connected;
			}
		}
	}

	if (connected > 1) return true; // 분리
	else if (connected == 0) { // 분리되지 않은 채로 전부 삭제
		isEmpty = true;
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) cin >> map[i][j];
	}

	int ans = 0;
	while(1) {
		memset(tmp, 0, sizeof(tmp));

		solve(); // 빙산 녹이기
		++ans;

		if (check()) break;
	} 

	if (isEmpty) cout << 0;
	else cout << ans;
	return 0;
}

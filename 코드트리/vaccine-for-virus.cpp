#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node { int y, x; };
const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };

const int MX = 51;
int N, M, map[MX][MX], dist[MX][MX], ans=MX*MX;
vector<Node> hospital, virus;

void bfs(queue<Node>& q) { 
		while (!q.empty()){
		Node cur = q.front(); q.pop();
		// dist[cur.y][cur.x] = 0; 동일한 좌표가 시작점으로 처리되는데 이때 dist가 바뀌게 돼

		for (int i = 0; i < 4; ++i) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];

			if (ny >= N || nx >= N || ny < 0 || nx < 0) continue;
			if (map[ny][nx] == 1 || dist[ny][nx] != -1) continue;

			dist[ny][nx] = dist[cur.y][cur.x] + 1;
			q.push({ ny, nx });
		}
	}

	int mx = 0; // -1이 아니라 0이야
	for (const auto& v : virus) {
		if (dist[v.y][v.x] == -1) return;
		mx = max(mx, dist[v.y][v.x]);
	}
	ans = min(ans, mx);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];

			if (map[i][j] == 0) virus.push_back({i, j});
			else if (map[i][j] == 2) hospital.push_back({ i, j });
		}
	}

	vector<int> mask(hospital.size(), 1); // 주의
	fill(mask.begin(), mask.begin()+M, 0); // 주의
	
	do {
		queue<Node> q; 
		fill(&dist[0][0], &dist[MX - 1][MX], -1); // 초기화도 여기에서

		for (int i = 0; i < hospital.size(); ++i) {
			if (mask[i] == 0) {
				q.push(hospital[i]);
				dist[hospital[i].y][hospital[i].x] = 0; // 여기서 병원 표시
			}
		}
		bfs(q);

	} while (next_permutation(mask.begin(), mask.end()));

	cout << (ans == MX * MX ? -1 : ans);
	return 0;
}
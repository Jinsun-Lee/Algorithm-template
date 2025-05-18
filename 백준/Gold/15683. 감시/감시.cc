//[Gold III] Title: 감시, ⭐벡터, Time: 4 ms, Memory: 2216 KB -BaekjoonHub
#include <iostream>
#include <queue> 
#include <vector>
#include <cstring>
using namespace std;

const int MX = 9;
int N, M, map[MX][MX], ans;

const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };

struct Camera { int c, y, x; }; //⭐

const vector<vector<vector<int>>> dirCam = {
	{},
	{{0}, {1}, {2}, {3}},
	{{2, 0}, {3, 1}},
	{{3, 0}, {0, 1}, {1, 2}, {2, 3}},
	{{2,3,0}, {3,0,1}, {0,1,2}, {1,2,3}},
	{{0,1,2,3}}
};

void cctv(int y, int x, int dir, bool vis[MX][MX]) {
	while (1) {
		y += dy[dir];
		x += dx[dir];
		if (y >= N || x >= M || y < 0 || x < 0 || map[y][x]==6) break;
		vis[y][x] = 1;
	}
}

void count(bool vis[MX][MX]) {
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (map[i][j]==0 && !vis[i][j]) cnt++;
		}
	}
	ans = min(ans, cnt);
}

void dfs(int dep, bool visit[MX][MX], const vector<Camera>& cams) {  //⭐const vector &
	if (dep==cams.size()) { //⭐
		count(visit);
		return;
	}

	bool backup[MX][MX];
	memcpy(backup, visit, sizeof(backup));

	const Camera& cam = cams[dep]; //⭐
	for (const auto& dirs : dirCam[cam.c]) {
		for (int d : dirs) cctv(cam.y, cam.x, d, visit);
		dfs(dep + 1, visit, cams); //
		memcpy(visit, backup, sizeof(backup)); //⭐
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	cin >> N >> M;
	ans = N * M; 

	vector<Camera> cams, cam5; //
	bool visit[MX][MX] = {}; 

	int cam;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> cam; map[i][j] = cam;
			if (cam == 0 || cam == 6) continue;
			if (cam == 5) cam5.push_back({ cam, i, j }); // 5일 때
			else cams.push_back({ cam, i, j }); 
		}
	}

	// 캠이 5일 때 먼저 처리
	while (!cam5.empty()) {
		Camera cam = cam5.back(); cam5.pop_back();
		for (int dir : dirCam[5][0]) cctv(cam.y, cam.x, dir, visit);
	}

	dfs(0, visit, cams); //
	cout << ans;
	return 0;
}
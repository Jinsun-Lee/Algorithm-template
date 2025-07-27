//[Gold III] Title: 감시, ⭐우선순위큐, Time: 4 ms, Memory: 2220 KB -BaekjoonHub
#include <iostream>
#include <queue> 
#include <vector>
#include <cstring>
using namespace std;

const int MX = 9;
int N, M, map[MX][MX], ans;

const int dy[4] = { 0, 1, 0, -1 }; // → ↓ ← ↑
const int dx[4] = { 1, 0, -1, 0 };

struct Camera {
	int c, y, x;
	bool operator < (const Camera& other) const { // const
		return c < other.c; // 54321로 내림차순 정렬
	}
};

const vector<vector<vector<int>>> dirCam = { //⭐const 꼭 붙여
	{}, // 카메라의 종류별 감시 방향 0번은 없음
	{{0}, {1}, {2}, {3} },                 // 1번 (→ ↓ ← ↑)
	{{0,2}, {1,3}},                        // 2번 (↔ ↕)
	{{3,0}, {0,1}, {1,2}, {2,3} },         // 3번 (└ ┌ ┐ ┘)
	{{2,3,0}, {3,0,1}, {0,1,2}, {1,2,3} }, // 4번 (ㅗ ㅏ ㅜ ㅓ)
	{{0,1,2,3} }                           // 5번 (+)
}; // 세미콜론 주의

void cctv(int y, int x, int dir, bool vis[MX][MX]) {
	while (1) { //⭐⭐이렇게 병합, while 안에 넣는 거 주의
		y += dy[dir];
		x += dx[dir];
		if (y >= N || x >= M || y < 0 || x < 0 || map[y][x]==6) break; //⭐
		vis[y][x] = 1;
	}
}

void count(bool vis[MX][MX]) {
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (map[i][j]==0 && !vis[i][j]) cnt++; // if (vis[i][j]) cnt++; 
		}
	}
	ans = min(ans, cnt);
}

void dfs(int dep, bool visit[MX][MX], priority_queue<Camera> cams) { 
	if (dep==0) { // dep<=0로 굳이 ㄴㄴ
		count(visit);
		return;
	}

	bool backup[MX][MX]; // int 아니고 bool
	memcpy(backup, visit, sizeof(backup)); // 사이즈백업

	Camera cam = cams.top(); cams.pop(); // cams.top()

	for (const auto& dirs : dirCam[cam.c]) { //⭐⭐const
		for (int d : dirs) cctv(cam.y, cam.x, d, visit);
		dfs(dep - 1, visit, cams); //⭐⭐2중 for문 아래야 주의
		memcpy(visit, backup, sizeof(backup)); //⭐⭐사이즈백업
	}

}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	cin >> N >> M;
	ans = N * M; // 초기화 

	priority_queue<Camera> cams;
	bool visit[MX][MX] = {}; // {} 주의, map이랑 분리 필수

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6) {
				cams.push({ map[i][j], i, j });
			}
		}
	}

	// 캠이 5일 때 먼저 처리
	while (!cams.empty() && cams.top().c == 5) { // cams.top().c에서 top이랑 c 붙는 거
		Camera cam = cams.top(); cams.pop();
		for (int dir : dirCam[5][0]) cctv(cam.y, cam.x, dir, visit);
	}

	dfs(cams.size(), visit, cams); 
	cout << ans;
	return 0;
}
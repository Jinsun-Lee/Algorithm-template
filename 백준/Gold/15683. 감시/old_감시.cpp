#include <iostream>
#include <queue> 
#include <vector>
#include <cstring>
using namespace std;

const int MX = 9;
int N, M, map[MX][MX], minn;

const int dy[4] = { 0, 1, 0, -1 };         // → ↓ ← ↑
const int dx[4] = { 1, 0, -1, 0 };

const vector<vector<vector<int>>> dirCam = { 
	// ⭐카메라의 종류별 감시 방향
	{}, // 0번은 없음
	{{0}, {1}, {2}, {3} },                 // 1번 (→ ↓ ← ↑)
	{{0,2}, {1,3}},                        // 2번 (↔ ↕)
	{{3,0}, {0,1}, {1,2}, {2,3} },         // 3번 (└ ┌ ┐ ┘)
	{{2,3,0}, {3,0,1}, {0,1,2}, {1,2,3} }, // 4번 (ㅗ ㅏ ㅜ ㅓ)
	{{0,1,2,3} }                           // 5번 (+)
};

void cctv(int y, int x, int dir, bool vis[MX][MX]) {
	while (1) { //⭐이렇게 병합
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
			//⭐if (vis[i][j]) cnt++; 
			if (map[i][j]==0 && !vis[i][j]) cnt++;
		}
	}
	minn = min(minn, cnt);
}

struct Camera {
	int c, y, x;
	bool operator < (const Camera& other) const { //⭐
		return c < other.c; // 54321로 내림차순 정렬
	}
};

void dfs(int dep, bool visit[MX][MX], priority_queue<Camera> cams) { 
	if (dep==0) {
		count(visit);
		return;
	}

	bool backup[MX][MX];
	memcpy(backup, visit, sizeof(backup));

	Camera cam = cams.top(); cams.pop();

	//⭐for (auto& dirs : dirCam[cam.c]) { 
	for (const auto& dirs : dirCam[cam.c]) {
		for (int dir : dirs) cctv(cam.y, cam.x, dir, visit);
		dfs(dep - 1, visit, cams);
		memcpy(visit, backup, sizeof(backup));
	}

}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	// 입력 받기
	cin >> N >> M;

	priority_queue<Camera> cams;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6) {
				cams.push({ map[i][j], i, j });
			}
		}
	}

	// 캠이 5일 때 먼저 소비
	bool visit[MX][MX] = {}; //⭐
	while (!cams.empty() && cams.top().c == 5) { 
		Camera cam = cams.top(); cams.pop();
		
		/*⭐ 굳이 2중 for 필요 없음
		for (auto&dirs : dirCam[5]) {
			for (int dir : dirs) cctv(cam.y, cam.x, dir, visit);
		}
		*/

		for (int dir : dirCam[5][0]) cctv(cam.y, cam.x, dir, visit);
	}

	minn = N * M; // 초기화 필수
	dfs(cams.size(), visit, cams); 
	cout << minn;
	return 0;
}
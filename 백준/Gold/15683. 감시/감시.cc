//[Gold III] Title: 감시, ⭐벡터, Time: 4 ms, Memory: 2216 KB -BaekjoonHub
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MX = 8;
int N, M, map[MX][MX], ans;

struct Camera { int c, y, x; }; //
vector<Camera> cams, cam5;

const int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};
const vector<vector<vector<int>>> dirCam = { // const 꼭 붙여
    {},
    {{0}, {1}, {2}, {3}},
    {{2, 0}, {3, 1}},
    {{3, 0}, {0, 1}, {1, 2}, {2, 3}},
    {{0, 2, 3}, {0, 1, 3}, {0, 1, 2}, {1, 2, 3}},
    {{0, 1, 2, 3}}
}; //⭐세미콜론 주의

void cctv(int y, int x, int dir, bool visit[MX][MX]) { 
    while (1) { //⭐while 주의
        y += dy[dir];
        x += dx[dir];
        if (y >= N || x >= M || y < 0 || x < 0 || map[y][x] == 6) break; //⭐
        visit[y][x] = 1;
    }
}

void count(bool visit[MX][MX]) {
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (map[i][j] == 0 && !visit[i][j]) cnt++;
        }
    }
    ans = min(ans, cnt);
}

void brute(int idx, bool visit[MX][MX]) {
    if (idx==cams.size()) { //⭐
        count(visit);
        return;
    }
    
    bool backup[MX][MX]; //⭐int 아니고 bool
    memcpy(backup, visit, sizeof(backup)); //⭐⭐⭐visit을 sizeof에 넣으면 안 돼

    const Camera& cam = cams[idx]; //const
    for (const auto& dirs : dirCam[cam.c]) {
        for (int d : dirs) cctv(cam.y, cam.x, d, visit); //⭐int로 써 꼭
        brute(idx + 1, visit);
        memcpy(visit, backup, sizeof(backup));
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen_s(new FILE*, "input.txt", "r", stdin);

    cin >> N >> M; 
    ans = N * M;

    int cam;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> cam; map[i][j] = cam;
            if (cam == 0 || cam == 6) continue;
            if (cam == 5) cam5.push_back({ cam, i, j });
            else cams.push_back({ cam, i, j });
        }
    }

    // 캠이 5일 때 먼저 처리
    bool visit[MX][MX] = {}; //⭐{} 주의, map이랑 분리 필수
    while (!cam5.empty()) {
        Camera cam = cam5.back(); cam5.pop_back();
        for (int dir : dirCam[5][0]) cctv(cam.y, cam.x, dir, visit); //⭐⭐⭐int로 써 꼭, 2중 for문 아냐         
    }

    brute(0, visit);
    cout << ans;
    return 0;
}

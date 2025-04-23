#include <iostream>
#include <vector>
using namespace std;
#define MX 101

int N;
bool map[MX][MX];

// 방향 d에 대해 0123이 각각 우상좌하
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int dir, ny, nx;

void dragon(int x, int y, int d, int g) {
    vector<int> mov;
    mov.push_back(d);

    while (g--) { // 차수만큼 반복
        // ⭐ 반시계 방향으로 추가가 됨=현재방향+1이랑 같음
        for (int i = mov.size() - 1; i >= 0; i--) { 
            // 반시계 회전... 아는데 편해서 (mov[i] + 1) % 4
            if (dir > 3) dir = 0;
            mov.push_back(dir);
        }
    }

    // N개의 줄에 대해 각 명령에 대한 g차 반복임
    ny = y; nx = x; // ⭐⭐⭐ 가장 끝점에 대해서 이어가야 하니까
    map[ny][nx] = 1; // 시작 지점

    for (int i = 0; i < mov.size(); i++) {
        ny += dy[mov[i]]; // ⭐⭐⭐
        nx += dx[mov[i]];

        // ⭐ 범위를 100까지
        if (ny > MX - 1 || nx > MX - 1 || ny < 0 || nx < 0) continue; 
        map[ny][nx] = 1;
    }

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen_s(new FILE*, "input.txt", "r", stdin);

    cin >> N;
    int x, y, d, g;
    for (int i = 0; i < N; i++) {
        cin >> x >> y >> d >> g;
        dragon(x, y, d, g);
    }

    // 전부 끝나면 정사각형 수 카운트
    int cnt = 0;
    for (int i = 0; i < MX - 1; i++) { // ⭐ 범위 99까지라 100보다 작게 해야 함 주의
        for (int j = 0; j < MX - 1; j++) {
            // 전부 더했을 때 합이 4일 때로도 표현 가능
            if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1]) cnt++;
        }
    }

    cout << cnt;

    return 0;
}
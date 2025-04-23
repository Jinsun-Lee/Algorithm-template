#include <iostream>
#include <vector>
using namespace std;
#define MX 101

int N;
bool map[MX][MX]; // map에 저장하고 카운트

int dir, ny, nx;

// 방향 d에 대해 0123이 각각 우상좌하
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };

void dragon(int x, int y, int d, int g) {
    vector<int> mov;
    mov.push_back(d);

    while (g--) {
        for (int i = mov.size() - 1; i >= 0; i--) { // ⭐ 동작이 필요한 방향 전부 추가
            dir = mov[i] + 1;
            if (dir > 3) dir = 0;
            mov.push_back(dir);
        }
    }

    // N개의 줄에 대해 각 명령에 대한 g차 반복임
    map[y][x] = 1; // 시작 지점

    ny = y; nx = x; // ⭐⭐⭐
    for (int i = 0; i < mov.size(); i++) {
        ny += dy[mov[i]]; // ⭐⭐⭐
        nx += dx[mov[i]];

        if (ny > MX - 1 || nx > MX - 1 || ny < 0 || nx < 0) continue; // ⭐ 범위를 100까지
        map[ny][nx] = 1;
    }

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen_s(new FILE*, "input.txt", "r", stdin);

    // 1. 입력 받기 
    cin >> N;
    int x, y, d, g; // 각 드래곤 커브의 명령
    for (int i = 0; i < N; i++) {
        cin >> x >> y >> d >> g;
        dragon(x, y, d, g);
    }

    // 전부 끝나면 정사각형 수 카운트
    int cnt = 0;
    for (int i = 0; i < MX - 1; i++) { // ⭐ 범위 99까지니 주의, 박스 체크도 ny nx 방식으로 가능
        for (int j = 0; j < MX - 1; j++) {
            if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1]) cnt++;
        }
    }

    cout << cnt;

    return 0;
}
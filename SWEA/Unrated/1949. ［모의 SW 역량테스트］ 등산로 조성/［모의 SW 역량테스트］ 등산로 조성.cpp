#include <iostream>
using namespace std;
 
const int MX = 9, dy[] = { -1, 0, 1, 0 }, dx[] = { 0, 1, 0, -1 };
int N, K, map[MX][MX], maxAns;
bool visited[MX][MX]; // 더 낮은 곳으로만 가서 괜찮은 줄 알았는데 중복 방문 체크 필요
 
void dfs(int y, int x, int depth, bool used) {
    visited[y][x] = 1;
 
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
 
        if (ny >= N || nx >= N || ny < 0 || nx < 0) continue;
        if (visited[ny][nx]) continue;
 
        // 아직 안 깎은 경우, 깎을 때
        if (used == false) {
            for (int k = 1; k <= K; ++k) {
                map[ny][nx] -= k;
                if (map[ny][nx] < map[y][x]) dfs(ny, nx, depth + 1, true);
                map[ny][nx] += k;
            }
        }
 
        // 안깎았는데 안깎을 때 + 깎은 경우
        if (map[ny][nx] < map[y][x]) dfs(ny, nx, depth + 1, used);
         
    }
    visited[y][x] = 0; // 얘도 있어야 함 주의
    maxAns = max(maxAns, depth);
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
     
    int tCase; cin >> tCase;
    for (int t = 1; t <= tCase; ++t) {
        cin >> N >> K;
 
        // 초기화
        for (int i = 0; i < MX;++i) fill(map[i], map[i] + MX, 0);
        int maxH = -1;
        maxAns = 1;
 
        // map 생성
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> map[i][j];
                if (map[i][j] > maxH) maxH = map[i][j];
            }
        }
         
        // 높은 지점에서 시작
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (map[i][j] == maxH) dfs(i, j, 1, false);
            }
        }
        cout << "#" << t << " " << maxAns << "\n";
    }
    return 0;
}
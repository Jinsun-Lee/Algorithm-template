#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int K, M, ori[5][5], more[300], idx = -1;
bool vis[5][5];

int BFS(int (&map)[5][5], bool canSave) { // 리턴 = 유물의 가치 = 3개 이상 같은 것이 연결된 것의 총 수
    memset(vis, 0, sizeof(vis));

    int total_cnt = 0; // 사라지게 될 유물의 수
    //int total_val = 0; // 삭제 시 얻을 가치의 합

    queue<pair<int, int>> q;
    vector<pair<int, int>> comp; //★따로 저장!!!

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {

            if (map[i][j] == 0) continue; //★ 0이 모여있을 때 터지면 안 돼...

            if (vis[i][j]) continue;
            vis[i][j] = true;

            int val = map[i][j];

            comp.clear(); //★★★초기화 필수

            q.push({ i, j });
            comp.push_back({ i,j });
            while (!q.empty()) {
                pair<int, int> c = q.front(); q.pop();

                for (int d = 0; d < 4; ++d) {
                    int ny = c.first + dy[d];
                    int nx = c.second + dx[d];

                    if (ny >= 5 || nx >= 5 || ny < 0 || nx < 0) continue;
                    if (vis[ny][nx] || map[ny][nx] != val) continue; // 값이 다르면 패스
                    vis[ny][nx] = true;
                    q.push({ ny, nx });
                    comp.push_back({ ny,nx }); //★따로 저장
                }
            }

            if ((int)comp.size() >= 3) { // cnt
                total_cnt += (int)comp.size();
                //total_val += ((int)comp.size() *val);

                //★이렇게 따로 갱신해
                if (canSave) {
                    for (auto& p : comp) map[p.first][p.second] = 0;
                }
            }

        }
    }

    return total_cnt; //{ total_cnt, total_val };
}

void rotate90(int y, int x, int(&map)[5][5]) { // (y, x)를 중심으로 3*3이 90도 시계방향 회전
    int tmp[3][3];

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            tmp[j][3 - 1 - i] = map[y - 1 + i][x - 1 + j]; //★좌표계 변환 + 한칸 미는 거 아니고 전부 회전임
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) map[y - 1 + i][x - 1 + j] = tmp[i][j];
    }
}

/*
void print(int map[5][5]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}
*/

void refill(int(&map)[5][5]) { // more 배열에서 가져와서 열부터 빈 칸 채우기
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (map[5 - j - 1][i] == 0) map[5 - j - 1][i] = more[++idx];
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> K >> M;

    // 원본 격자 받기
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) cin >> ori[i][j];
    }

    // 여분의 유물 받기
    for (int i = 0; i < M; ++i) cin >> more[i];

    // 탐사 진행
    while (K--) {
        int ans = 0; // 이번턴의 점수 = 가치의 총합

        int bMap[5][5];     // (set 대체) 가치의수, 회전각도, 열, 행
        int bReward = -1;   // 최대로 제거할 수 있는 유물의 개수
        int bAngle = 0;     // 회전 각도
        int bR = 0, bC = 0; // 3*3 중심 좌표

        // 3*3 격자의 최대 가치를 찾아 열, 행 작은 것 택
        for (int i = 1; i <= 3; ++i) {
            for (int j = 1; j <= 3; ++j) {

                int map[5][5];
                memcpy(map, ori, sizeof(ori));

                // 90도일 때 가치 탐색, 180, 270
                int curAng = 90;
                for (int rot = 1; rot <= 3; ++rot, curAng += 90) {

                    rotate90(i, j, map);
                    int tCnt = BFS(map, false); // 제거 가능한 유물 개수

                    // tCnt유물개수큰순 > 각도작은거 > 열작은거 > 행작은거
                    bool better = false;
                    if (tCnt > bReward) better = true;
                    else if (tCnt == bReward) {

                        if (curAng < bAngle) better = true;
                        else if (curAng == bAngle) {

                            if (j < bC) better = true;
                            else if (j == bC) {

                                if (i < bR) better = true;
                            }
                        }
                    }

                    if (better) {
                        bReward = tCnt;
                        bAngle = curAng;
                        bC = j; bR = i;
                        memcpy(bMap, map, sizeof(bMap));
                    }
                }

            }
        }


        // 3개 이상 못 없애서 남은 턴은 점수 변화 없음 
        if (bReward < 3) break;

        // 최고 상태인 격자를 업데이트 해 둬야 해
        memcpy(ori, bMap, sizeof(ori));

        // 연쇄 처리
        while (1) {
            int tCnt = BFS(ori, true); // 제거 수행
            if (tCnt < 3) break; // 3개 미만이면 종료
            ans += tCnt;
            refill(ori);
        }

        //memcpy(ori, bMap, sizeof(ori));
        cout << ans << " ";
    }

    return 0;
}

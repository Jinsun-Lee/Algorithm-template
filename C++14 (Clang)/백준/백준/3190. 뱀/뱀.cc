#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MX = 102;
int map[MX][MX]; //-1뱀벽 0빈칸 1사과
int N; //맵

const int dy[4] = {0,1,0,-1}; //우하좌상
const int dx[4] = {1,0,-1,0};
int movDir = 0; //진행방향 초기 우

queue< pair<int, int> > qPath; //y x
queue< pair<int, int> > qTime; //시간, 인덱스처리
int nxtT=-1; //추후 언제 회전 하는지

void input() {
    int K, y, x;
    cin >> N >> K;

    //사과 표시
    for (int i = 0; i < K; ++i) {
        cin >> y >> x;
        map[y][x] = 1;
    }

    //이동 방향
    int L, t;
    char dir;
    cin >> L;
    for (int i = 0; i < L; ++i) {
        cin >> t >> dir;
        qTime.push({ t, (dir=='D' ? 1:-1) }); //D우1 L좌-1
    }

    if (!qTime.empty()) nxtT = qTime.front().first;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    input();

    int curT = 1; //답

    qPath.push({ 1, 1 }); //시작위치
    map[1][1] = -1;

    while (!qPath.empty()) {
        //최신에 추가한게 현재 좌표, ny nx는 이동할 좌표
        int ny = qPath.back().first + dy[movDir];
        int nx = qPath.back().second + dx[movDir];

        //벽이거나 뱀이면 종료
        if (ny==N+1 || nx==N+1 || ny==0 || nx==0 || map[ny][nx]==-1) break;
        //if (ny > N || nx > N || ny < 1 || nx < 1 || map[ny][nx] == -1) break;

        if (map[ny][nx] == 0) { //⭐벽이면 오래된 것 = 가장 끝 제거
            map[qPath.front().first][qPath.front().second] = 0; //⭐꼬리 제거
            qPath.pop();
        }

        map[ny][nx] = -1; //⭐이동전 반영하면 사과먹음 따로 표시 안 해도 돼
        qPath.push({ ny, nx }); //⭐실제로 이동, 벽이든 사과든 새좌표 추가

        //x초 끝나고 회전
        if (curT == nxtT) { //이번에 회전한다면
            movDir = (movDir + qTime.front().second + 4) %4; //범위 0~3고정 모듈러연산
            qTime.pop();
            if (!qTime.empty()) nxtT = qTime.front().first; //다음 정보로 갱신
        }

        curT++;
    }

    cout << curT;
    return 0;
}
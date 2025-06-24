#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MX = 102;
int map[MX][MX]; // -1 뱀이나벽 0빈칸 1사과
int N; // 격자 크기

const int dy[4] = {0,1,0,-1}; // 우하좌상
const int dx[4] = {1,0,-1,0};
int movDir = 0; // 진행방향 초기 우

queue< pair<int, int> > qPath; // y, x
queue< pair<int, int> > qTime; // 시간, 인덱스처리
int nxtT=-1; // 추후 언제 회전해야 하는지

void input() {
    int K, y, x;
    cin >> N >> K;

    // 사과의수 K줄, 맵에 사과 표시
    for (int i = 0; i < K; ++i) {
        cin >> y >> x;
        map[y][x] = 1;
    }

    // 뱀의 이동 방향
    int L, t; 
    char dir;
    cin >> L;
    for (int i = 0; i < L; ++i) {
        cin >> t >> dir;
        qTime.push({ t, (dir=='D' ? 1:-1) }); // D우1 L좌-1
    }

    if (!qTime.empty()) nxtT = qTime.front().first;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    input();

    int curT = 1; // 답
    
    qPath.push({ 1, 1 }); // 시작 위치
    map[1][1] = -1;

    while (!qPath.empty()) {
        // 최신에 추가한게 현재 좌표
        int ny = qPath.back().first + dy[movDir];
        int nx = qPath.back().second + dx[movDir];

        // 벽의 테두리거나 뱀의 몸이면 종료
        if (ny==N+1 || nx==N+1 || ny==0 || nx==0 || map[ny][nx]==-1) break;
        //if (ny > N || nx > N || ny < 1 || nx < 1 || map[ny][nx] == -1) break;
        
        // 문제의 구간
        if (map[ny][nx] == 0) { // 벽이면 오래된 것 = 가장 끝 제거
            map[qPath.front().first][qPath.front().second] = 0; // 꼬리 제거한다고 말해줘야지
            qPath.pop(); 
        }

        map[ny][nx] = -1;
        qPath.push({ ny, nx }); // 벽이든 사과든 현재 위치 추가

        // x초 끝나고 회전
        if (curT == nxtT) { // 이번 시간에 회전한다면
            movDir = (movDir + qTime.front().second + 4) %4; // 이동방향 범위 0~3고정 모듈러연산
            qTime.pop();
            if (!qTime.empty()) nxtT = qTime.front().first; // 다음 시간 정보로 갱신
        }
        
        curT++;
    }

    cout << curT;
    return 0;
}
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
using ll = long long;

const int dy[] = {0, -1, 0, 1, 0}; // 좌상우하 + 그대로
const int dx[] = {-1, 0, 1, 0, 0};

int N, K, L; // 격자크기, 청소기의수, 테스트의수
int board[32][32]; // -1물건, 0~100 먼지양
int r_board[32][32]; // 이보드에서는1~로봇 / robots[i-1]로 접근해

struct Robot {
    int id, y, x;
};
vector<Robot> robots;
//vector<Munji> munjis; //🔥먼지는 이중for문으로 처리

void input() {
    memset(board, 0, sizeof(board));
    memset(r_board, 0, sizeof(r_board)); 
    robots.clear();

    cin >> N >> K >> L;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) cin >> board[i][j];
    }

    robots.resize(K);
    int y, x;
    for (int i = 0; i < K; ++i) {
        cin >> y >> x;
        r_board[y][x] = i+1;
        robots[i] = { i + 1, y, x };
    }
}

void moveRobot(Robot& r) { // 1. 청소기의 이동
    //🔥현재 칸이 더러우면 이동하지 않아 
    if (board[r.y][r.x] > 0) return; 

    //🔥BFS
    queue<pair<int, int>> q;
    vector<vector<int>> dist(N+2, vector<int>(N+2, -1));
    q.push({ r.y, r.x });
    dist[r.y][r.x] = 0;

    int bestDist = -1;
    pair<int, int> bestCell = { -1, -1 }; // (r, c)

    while (!q.empty()) {
        auto c = q.front(); q.pop();
        int y = c.first, x = c.second;

        // 이미 최단 오염칸 거리(bestDist)를 찾았고, 그보다 먼 거리는 중단
        if (bestDist != -1 && dist[y][x] > bestDist) break;

        for (int d = 0; d < 4; ++d) {
            int ny = y + dy[d];
            int nx = x + dx[d];

            if (ny < 1 || nx<1 || ny>N || nx>N) continue;
            if (dist[ny][nx] != -1) continue; 
            if (board[ny][nx] ==-1) continue; // 다른 물건
            if (r_board[ny][nx] > 0) continue; // 다른 로봇이 있어
       
            dist[ny][nx] = dist[y][x] + 1;
            q.push({ ny, nx });

            if (board[ny][nx] > 0) { // 오염 칸 발견
                if (bestDist == -1 || bestDist == dist[ny][nx]) {
                    if (bestDist == -1) {
                        bestDist = dist[ny][nx];
                        bestCell = { ny, nx };
                    }
                    else bestCell = min(bestCell, make_pair(ny, nx));
                }
            }

        }
    }

    if (bestDist != -1) {
        r_board[r.y][r.x] = 0;
        r.y = bestCell.first;
        r.x = bestCell.second;
        r_board[r.y][r.x] = r.id;
    }
}

void cleanRobot(const Robot& r) { // 2. 청소
    // 5칸 중 제외할 1칸 고르는 문제
    
    // 바라보고 있는 방향 기준으로, 본인이 위치한 격자, 왼쪽, 위쪽, 오른쪽 청소 가능
    // 청소 가능한 4가지 격자에서 청소할 수 있는 먼지량이 가장 큰 방향부터 청소
    // 합이 같으면 오른쪽, 아래, 왼쪽, 위쪽 우선순위로 방향 택
    // 각 격자마다 최대 20 청소 가능
    // 청소기마다 순서대로 진행

    int bestNoDir = -1; // 방향 작은 것
    int bestSum = 0; // 합큰것

    for (int no = 0; no < 4; ++no) { // 이 방향 빼고, 좌, 상, 우, 하 뺄 거야
        int sum = 0;

        // 어느 방향의 값이 젤 많은지 확인
        for (int d = 0; d < 5; ++d) { // 우 하 좌 상 준으로 택하게 돼 
            int ny = r.y + dy[d];
            int nx = r.x + dx[d];

            if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
            if (d == no && d < 4) continue; // 제외 방향은 패쓰
            if (board[ny][nx] > 0) sum += min(20, board[ny][nx]); //🔥
        }

        if (bestNoDir == -1 || sum > bestSum) {
            bestNoDir = no;
            bestSum = sum;
        }
    }

    if (bestSum > 0 && bestNoDir != -1) {
        // 우에 있는 모든 좌표를 0으로 만들 건데, 20까지만 지울 수 있어
        // 그럼 어디를 기준으로 나머지를 남기지
        for (int d = 0; d < 5; ++d) {
            int ny = r.y + dy[d];
            int nx = r.x + dx[d];

            if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
            if (d == bestNoDir && d < 4) continue; // 제외 방향은 패쓰
            if (board[ny][nx] > 0) board[ny][nx] = max(0, board[ny][nx] - 20); //🔥
        }
    }
}

void actionMunji() {
    // 먼지가 있는 모든 격자에 먼지 + 5   
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) if (board[i][j] > 0) board[i][j] += 5;
    }

    // 격자의 먼지량의 합을 10으로 나눈 값만큼 먼지가 확산
    // 깨끗한 격자에 대해 동시에 확산함
    vector<vector<int>> tmp(N+2, vector<int>(N+2, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {

            if (board[i][j] == 0) { // 깨끗한 칸으로만 확산
                int sum = 0; 
                for (int d = 0; d < 4; ++d) {
                    int ny = i+ dy[d];
                    int nx = j + dx[d];
                    if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
                    if (board[ny][nx] > 0) sum += board[ny][nx];
                }
                tmp[i][j] = sum / 10;
            }
        }
    }

    for (int i = 1; i <= N; ++i) { 
        for (int j = 1; j <= N; ++j) board[i][j]+= tmp[i][j];
    }
}

int print() { //합을 출력
    ll sum = 0; 
    for (int i = 1; i <= N; ++i) { 
        for (int j = 1; j <= N; ++j)
            if (board[i][j] > 0) sum += board[i][j];
    }
    return sum;
}

int main() {
    //freopen_s(new FILE*, "input.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);

    input();
    while (L--) {
        for (auto& r : robots) moveRobot(r); //🔥
        for (auto& r : robots) cleanRobot(r);
        actionMunji();
        
        ll sum = print(); //🔥ll로 합을 구하고
        cout << sum << "\n";
        if (sum == 0) break; // 조기 종료
    }
    return 0;
}

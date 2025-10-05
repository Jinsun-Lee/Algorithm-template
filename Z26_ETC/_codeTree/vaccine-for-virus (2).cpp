#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

const int MX = 51;
int map[MX][MX]; // 0바이러스, 1벽, 2병원
int vis[MX][MX];

int N, M, ans;

struct Node { int y, x; };
vector<Node> hospital, virus, selec;

void BFS(vector<Node>& selec) {
    fill(&vis[0][0], &vis[0][0] + MX * MX, 0x7fffffff);
    
    queue<Node> q;
    for (const auto& c : selec) q.push(c);

    while (!q.empty()) {
        auto& c = q.front(); q.pop();

        for (int d = 0; d < 4; ++d) {
            int ny = c.y + dy[d];
            int nx = c.x + dx[d];

            if (ny >= N || nx >= N || ny < 0 || nx < 0) continue;
            if (map[ny][nx] == 1 || map[ny][nx] == 2) continue;
            if (vis[ny][nx] <= vis[c.y][c.x] + 1) continue;
            vis[ny][nx] = vis[c.y][c.x] + 1;
            q.push({ ny, nx });
        }
    }

    for (const auto& v : virus) {
        if (vis[v.y][v.x] == 0x7fffffff) {
            ans = -1;
            break;
        }
        else ans = max(ans, vis[v.y][v.x]);
    }
}

void DFS(int dep, vector<Node>& selec) {
    if (dep == M) {
        BFS(selec);
        return;
    }

    DFS(dep+1, selec);
    selec.push_back(hospital[dep]);
    DFS(dep + 1, selec);
    selec.pop_back();;
}

int main() {
    //freopen_s(new FILE*, "input.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M; // 격자 크기, 병원의 수
   
    //int cnt = 0; // 처음에 바이러스가 몇 개 있는지
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> map[i][j];

            if (map[i][j] == 2) hospital.push_back({ i, j });
            else if (map[i][j] == 0) virus.push_back({ i, j });
        }
    }

    DFS(0, selec);
    cout << ans;
    return 0;
}

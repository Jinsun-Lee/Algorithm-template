#include <iostream>
#include <vector>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

struct Node { int y, x; };
vector<Node> start;

int N, K;
int ans = 0;

const int MX = 9;
int map[MX][MX];
bool vis[MX][MX]; 

void DFS(int dep, int y, int x, int v, bool canCut) {
	if (ans < dep) ans = dep;

	for (int d = 0; d < 4; ++d) {
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		if (vis[ny][nx]) continue;

		if (map[ny][nx] < v) { // 그냥 이동
			vis[ny][nx] = true;
			DFS(dep + 1, ny, nx, map[ny][nx], canCut);
			vis[ny][nx] = false;
		}
		else if (canCut == true) { // 자르고 이동
			for (int p = K; p > 0; --p) {
				if (map[ny][nx] - p >= v) continue;
				vis[ny][nx] = true;
				DFS(dep + 1, ny, nx, map[ny][nx] - p, false);
				vis[ny][nx] = false;
			}			
		}
	}
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	ios::sync_with_stdio(0); cin.tie(0);
	
	int tc; cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		cin >> N >> K;

		ans = 0;
		start.clear();
		//fill(&vis[0][0], &vis[0][0] + MX * MX, false);

		int mxH = -1;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> map[i][j];

				if (map[i][j] > mxH) {
					mxH = map[i][j];
					start.clear();
					start.push_back({ i, j });
				}
				else if (map[i][j] == mxH) start.push_back({ i, j });
			}
		}

		for (auto& c : start) {
			vis[c.y][c.x] = true;
			DFS(1, c.y, c.x, mxH, true);
			vis[c.y][c.x] = false;
		}
		cout << "#" << t << " " << ans<<"\n";
	}
	return 0;
}
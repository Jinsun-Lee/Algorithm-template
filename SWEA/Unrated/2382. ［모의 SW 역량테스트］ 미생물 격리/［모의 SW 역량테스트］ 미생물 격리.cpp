#include <iostream>
#include <vector>
using namespace std;

struct Cell { int y, x, cnt, dir; };

const int dy[5] = {0,-1,1,0,0}, dx[5] = {0,0,0,-1,1};
const int newDir[5] = {0,2,1,4,3};

const int MX = 101;
int sumCnt[MX][MX], maxCnt[MX][MX], maxDir[MX][MX];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		int N, M, K; cin >> N >> M >> K;

		vector<Cell> cells;
		cells.reserve(K);

		for (int i = 0; i < K; ++i) {
			Cell c;
			cin >> c.y >> c.x >> c.cnt >> c.dir;
			cells.push_back(c);
		}

		vector<pair<int, int>> visited;
		visited.reserve(K);

		while (M--) {
			visited.clear();

			for (auto& cur : cells) {
				int ny = cur.y + dy[cur.dir];
				int nx = cur.x + dx[cur.dir];

				if (ny == N - 1 || nx == N - 1 || ny == 0 || nx == 0) {
					cur.cnt >>= 1;
					if (cur.cnt == 0) continue;
					cur.dir = newDir[cur.dir];
				}

				if (sumCnt[ny][nx] == 0) {
					visited.emplace_back(ny, nx);
					maxCnt[ny][nx] = 0;
				}

				sumCnt[ny][nx] += cur.cnt;
				if (cur.cnt > maxCnt[ny][nx]) {
					maxCnt[ny][nx] = cur.cnt;
					maxDir[ny][nx] = cur.dir;
				}
			}

			cells.clear();
			for (auto& p : visited) {
				int y = p.first, x = p.second;
				cells.push_back({ y, x, sumCnt[y][x], maxDir[y][x] });

				sumCnt[y][x] = maxCnt[y][x] = maxDir[y][x] = 0;
			}
		}

		int ans = 0;
		for (const auto& c : cells) ans += c.cnt;
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}
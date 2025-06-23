#include <iostream>
#include <vector>
using namespace std;

const int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
const int newDir[4] = { 1, 0, 3, 2 }; // 상하좌우 -> 반대방향

int N, M, K;

struct Cell { int y, x, cnt, dir; };
vector<Cell> cells; // y, x, 군집수, 방향
vector<pair<int, int>> visited;

const int MX = 101;
int sumCnt[MX][MX], maxCnt[MX][MX], maxDir[MX][MX];

void input() {
	cin >> N >> M >> K;

	cells.clear(); // 주의
	cells.reserve(K); // 재할당 최소화
	visited.reserve(K); 

	int y, x, cnt, dir;
	while (K--) {
		cin >> y >> x >> cnt >> dir;
		cells.push_back({ y, x, cnt, dir - 1 });
	}
}

void move() {
	// 초기화 memset보다 효율
	visited.clear();

	// 일단 전부 이동
	for (auto& cur : cells) {
		int ny = cur.y + dy[cur.dir];
		int nx = cur.x + dx[cur.dir];

		// 이동 후 빨간 테두리면 절반(0이면 추가X), 반대 
		if (ny == N - 1 || nx == N - 1 || ny == 0 || nx == 0) {
			cur.cnt >>= 1; // 비트 시프트로 나눗셈 대체 cur.cnt /= 2;
			if (cur.cnt == 0) continue;
			cur.dir = newDir[cur.dir];
		}

		// 접근한 것만 기록 + 초기 접근 시 초기화
		if (sumCnt[ny][nx] == 0) {
			visited.emplace_back(ny, nx);
			maxCnt[ny][nx] = 0; // 별도로 필요
		}

		sumCnt[ny][nx] += cur.cnt;
		if (cur.cnt > maxCnt[ny][nx]) {
			maxCnt[ny][nx] = cur.cnt;
			maxDir[ny][nx] = cur.dir;
		}
	}

	// 합치기 동작
	cells.clear();
	for (auto& p : visited) {
		int y = p.first, x = p.second;
		cells.push_back({ y, x, sumCnt[y][x], maxDir[y][x] });

		// 접근한 위치만 초기화
		sumCnt[y][x] = maxCnt[y][x] = maxDir[y][x] = 0;
	}
}

int cntCells() {
	int sum = 0;
	for (const auto& c : cells) sum += c.cnt;
	return sum;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		input();
		while (M--) move();
		cout << "#" << t << " " << cntCells() << "\n";
	}
	return 0;
}
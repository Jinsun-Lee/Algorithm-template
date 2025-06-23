#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 }; // 상하좌우
const int MX = 100;
int N, M, K; // 크기, 반복시간, 미생물군집수 1000개

struct Cell { int y, x, cnt, dir; };

vector<Cell> cells; // y, x, 군집수, 방향

void input() {
	cells.clear(); // 주의!!!!!!

	cin >> N >> M >> K;

	int y, x, cnt, dir;
	while (K--) {
		cin >> y >> x >> cnt >> dir;
		cells.push_back({y, x, cnt, dir-1});
	}
}

int newDir(int dir) {
	if (dir == 0 || dir == 2) return dir + 1;
	else return dir - 1; // 1,  3일 때
}

void move() {
	//vector<vector<vector<Cell>>> map(N, vector<vector<Cell>>(N));
	static Cell* nxtMap[MX][MX] = {};
	static int sumCnt[MX][MX] = {};
	static int maxCnt[MX][MX] = {};
	static int maxDir[MX][MX] = {};

	// 초기화
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			sumCnt[i][j] = maxCnt[i][j] = maxDir[i][j] = 0;
	}

	// 일단 전부 이동을 해
	for (auto& cur : cells) {
		int ny = cur.y + dy[cur.dir];
		int nx = cur.x + dx[cur.dir];

		// 이동 후 빨간 테두리면 절반(0이면 추가X), 이동 반대 
		if (ny == N - 1 || nx == N - 1 || ny == 0 || nx == 0) {
			int half = cur.cnt / 2; 
			if (half == 0) continue;
			cur.cnt = half;
			cur.dir = newDir(cur.dir);
		}

		sumCnt[ny][nx] += cur.cnt;
		if (cur.cnt > maxCnt[ny][nx]) {
			maxCnt[ny][nx] = cur.cnt;
			maxDir[ny][nx] = cur.dir;
		}
	}

	// 합치기 동작
	cells.clear();
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (sumCnt[i][j]==0) continue;
			cells.push_back({i, j, sumCnt[i][j], maxDir[i][j]});
		}
	}
}

int cntCells() {
	int sum = 0;
	for (const Cell& c : cells) sum += c.cnt; // 이중for문 X
	return sum;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		input();

		while (M--) move();

		cout << "#" << t << " " << cntCells() << "\n";
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 }; // 상하좌우
const int newDir[4] = { 1, 0, 3, 2 }; // 새로운 방향, 함수 대체

int N, M, K; // 격자크기, 반복시간, 미생물군집수

struct Cell { int y, x, cnt, dir; };
vector<Cell> cells; // y, x, 군집수, 방향

const int MX = 100;
int sumCnt[MX][MX], maxCnt[MX][MX], maxDir[MX][MX];

void input() {
	cin >> N >> M >> K;

	cells.clear(); // 초기화
	cells.reserve(K); // 재할당 최소화

	int y, x, cnt, dir;
	while (K--) {
		cin >> y >> x >> cnt >> dir;
		cells.push_back({y, x, cnt, dir-1});
	}
}

void move() {
	// 초기화
	memset(sumCnt, 0, sizeof(sumCnt));
	memset(maxCnt, 0, sizeof(maxCnt));
	memset(maxDir, 0, sizeof(maxDir));

	// 일단 전부 이동을 해
	for (auto& cur : cells) {
		int ny = cur.y + dy[cur.dir];
		int nx = cur.x + dx[cur.dir];

		// 이동 후 빨간 테두리면 절반(0이면 추가X), 이동 반대 
		if (ny == N - 1 || nx == N - 1 || ny == 0 || nx == 0) {
			cur.cnt >>= 1; // 비트 시프트로 나눗셈 대체 cur.cnt /= 2;
			if (cur.cnt == 0) continue; 
			cur.dir = newDir[cur.dir];
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
	// cur.cnt를 continue 뒤에서 갱신해도 continue라 어차피 sumCnt에 안 더해서 괜찮아 cells.clear()하고 갱신하니까
	int sum = 0;
	for (const Cell& c : cells) sum += c.cnt; // 이중for문 X
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
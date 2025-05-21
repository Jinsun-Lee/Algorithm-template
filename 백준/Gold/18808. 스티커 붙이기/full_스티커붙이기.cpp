#include <iostream>
using namespace std;

const int MX = 10;
int N, M, K, R, C;
bool map[40][40], sticker[MX][MX];

void turnCW() {
	int tmp[MX][MX];
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			tmp[j][R-i-1] = sticker[i][j]; // 시계 90
		}
	} swap(R, C);

	//memcpy(sticker, tmp, sizeof(tmp)); 안 돼
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			sticker[i][j] = tmp[i][j];
		}
	}	
}

bool pastable(int y, int x) {
	// 붙일수 있는지 먼저 확인
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (map[y+i][x+j] && sticker[i][j]) return false; // 못붙여
		}
	}

	// 붙일 수 있으면 map 갱신
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (sticker[i][j]) map[y+i][x+j] = 1;
		}
	}
	return true;
}

bool match() {
	bool isPaste = false; // 스티커 붙였는지
	for (int i = 0; i < N-R+1 && !isPaste; ++i) { // N-R+1에 등호 안 붙는다
		for (int j = 0; j < M-C+1; ++j) {
			if (pastable(i, j)) { // 붙일 수 있으면
				isPaste = true;
				break;
			}
		}
	}
	return isPaste;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N >> M >> K; // 1. 세로, 가로, 스티커의 수
	while (K--) {

		cin >> R >> C; // 2. 스티커의 행열, 격자 받기
		for (int i = 0; i < R; ++i) { 
			for (int j = 0; j < C; ++j) cin >> sticker[i][j];
		}

		// 3. 어디에 붙일지 
		for (int i = 0; i < 4; ++i) { // 0 90 180 270
			if (match() || i == 3) break; // 붙여서 ready거나 270도는 회전X라 for문 종료
			turnCW(); // false는 못붙이니 돌려
		}
	}

	// 4. 세고 출력
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) ans += (int)map[i][j]; // = int(map[i][j]) = if (map[i][j]) ans++;
	} cout << ans;
	return 0;
}
#include <iostream>
using namespace std;

const int MX = 10;
int N, M, K, R, C;
bool map[40][40], sticker[MX][MX];

void turnCW() {
	int tmp[MX][MX];
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			tmp[j][R-i-1] = sticker[i][j]; 
		}
	} swap(R, C);
	
	for (int i = 0; i < R; ++i) { 
		for (int j = 0; j < C; ++j) sticker[i][j] = tmp[i][j];
	}	
}

bool pastable(int y, int x) {
	//⭐RC 스티커 범위를 기준, 붙일 수 있는지 먼저 확인
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

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> K;
	while (K--) {
		cin >> R >> C; 
		for (int i = 0; i < R; ++i) { 
			for (int j = 0; j < C; ++j) cin >> sticker[i][j];
		}

		for (int d = 0; d < 4; d++) { 
			bool isPaste = false; // 위치 주의

			for (int i = 0; i <= N-R && !isPaste; i++) {
				for (int j = 0; j <= M-C; ++j) {
					isPaste = pastable(i, j);
					if (isPaste) break;
				}
			} // N-R 끝
			
			if (isPaste || d == 3) break; 
			turnCW();
			
		} // d4 끝
	} // while 끝

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) ans += (int)map[i][j];
	} cout << ans;
	return 0;
}

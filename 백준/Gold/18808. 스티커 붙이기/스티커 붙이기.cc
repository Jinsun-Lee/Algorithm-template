#include <iostream>
using namespace std;

const int MX = 10;
int N, M, K, R, C;
bool map[40][40], sticker[MX][MX];

void turnCW() {
	int tmp[MX][MX];
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) tmp[j][R-i-1] = sticker[i][j];
	} swap(R, C); 
    
    // 주의
	for (int i = 0; i < R; ++i) { 
		for (int j = 0; j < C; ++j) sticker[i][j] = tmp[i][j];
	}	
}

bool pastable(int y, int x) {
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (map[y+i][x+j] && sticker[i][j]) return false; // 못붙여
		}
	}
    
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (sticker[i][j]) map[y+i][x+j] = 1;
		}
	}
	return true;
}

bool match() {
	bool isPaste = false; // 스티커 붙였어?
	for (int i = 0; i < N-R+1 && !isPaste; ++i) { 
		for (int j = 0; j < M-C+1; ++j) {
			if (pastable(i, j)) { // 붙일 수 있음
				isPaste = true;
				break;
			}
		}
	}
	return isPaste;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> K;
	while (K--) {

		cin >> R >> C;
		for (int i = 0; i < R; ++i) { 
			for (int j = 0; j < C; ++j) cin >> sticker[i][j];
		}

		for (int i = 0; i < 4; ++i) {
			if (match() || i == 3) break; 
			turnCW();
		}
	}

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) ans += (int)map[i][j]; 
	} cout << ans;
	return 0;
}
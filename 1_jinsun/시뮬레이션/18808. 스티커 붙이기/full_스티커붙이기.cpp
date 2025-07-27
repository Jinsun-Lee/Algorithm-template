#include <iostream>
using namespace std;

const int MX = 10;
int N, M, K, R, C;
bool map[40][40], sticker[MX][MX];

// 시계 방향은 N인 거랑, 정사각형 아니라서 swap하고 for문으로 넣어
// 스티커는 R, C잖아... NM말고
void turnCW() {
	int tmp[MX][MX];
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			tmp[j][R-i-1] = sticker[i][j]; // 시계 90
		}
	} swap(R, C);

	//memcpy(sticker, tmp, sizeof(tmp)); 안 돼
	for (int i = 0; i < R; ++i) { 
		for (int j = 0; j < C; ++j) sticker[i][j] = tmp[i][j];
	}	
}

//⭐붙일 수 있는지는 RC 스티커 범위를 기준으로 돌려
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
	for (int i = 0; i < N-R+1; ++i) {
		for (int j = 0; j < M-C+1; ++j) {
			if (pastable(i, j)) return true; // 붙일 수 있으면
		}
	}
	return false;
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
		/* 방법1
  		for (int d = 0; d < 4; ++d) { // 0 90 180 270
			if (match() || d == 3) break; // 붙여서 ready거나 270도는 회전X라 for문 종료
			turnCW(); // false는 못붙이니 돌려
		}
 		*/

		//⭐방법2
		//bool pasted = false;
		for (int d = 0; d < 4; d++) { 
			bool isPaste = false; // 위치 주의

			// 붙일 수 있나 확인하고, 붙일 수 있으면 붙여
			for (int i = 0; i <= N-R && !isPaste; i++) { // i<N-R+1 or i<=N-R
				for (int j = 0; j <= M-C; ++j) {
					isPaste = pastable(i, j);
					if (isPaste) break;
				}
			}

			// 붙였거나, 270도면 회전X
			if (isPaste || d == 3) break; 
			turnCW();
		}

	}

	// 4. 세고 출력
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) ans += (int)map[i][j]; // = int(map[i][j]) = if (map[i][j]) ans++;
	} cout << ans;
	return 0;
}

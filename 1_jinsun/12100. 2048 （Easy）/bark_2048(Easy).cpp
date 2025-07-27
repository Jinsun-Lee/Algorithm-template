//2216	12	1686
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MX = 21;
int N, ans = 0;
int map[MX][MX]; // 입력으로 받은 원본
int src[MX][MX]; // 매번 복사한 맵

void turnCW() {
	int tmp[MX][MX];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) tmp[j][N - i - 1] = src[i][j];
	}
	memcpy(src, tmp, sizeof(tmp));
}

void tilt(int dir) {
	while (dir--) turnCW(); // 기울인 후 시계 방향으로 돌린다고 생각하면 돼(반시계로 다시 돌리지 않아도 돼)

	for (int i = 0; i < N; i++) {
		int dst[MX] = {}; // src[i]을 기울인 결과를 저장
		int idx = 0;      // 다음에 숫자가 들어갈 위치

		for (int j = 0; j < N; j++) {
			if (src[i][j] == 0) continue;

			if (dst[idx] == 0)              dst[idx] = src[i][j];   // 삽입할 위치가 비어있을 경우
			else if (dst[idx] == src[i][j]) dst[idx++] *= 2;        // 같은 값을 갖는 블록이 충돌
			else                            dst[++idx] = src[i][j];	// 다른 값을 갖는 블록이 충돌				
		}

		for (int j = 0; j < N; j++){
			src[i][j] = dst[j]; // src[i]에 dst를 덮어씀
		} 
	}
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) cin >> map[i][j];
	}

	// 한번 기울일 때 상우하좌 4방향, 최대 5번 이동 가능
	// 4*4*4*4*4 = 4^5 = 1024로, tmp의 각 자리수는 한 번의 이동 방향을 의미
	for (int tmp = 0; tmp < 1024; tmp++) {

		memcpy(src, map, sizeof(map)); // 매번 복사

		int brute = tmp;
		for (int i = 0; i < 5; i++) { // 최대 5번 이동
			int dir = brute % 4;  // 1의 자리 = 각 4방향
			brute /= 4;           // 다음 자리를 위해
			tilt(dir);
		}

		// 가장 큰 값 갱신
		for (int i = 0; i < N; i++) {
			ans = max(ans, *max_element(src[i], src[i] + N));
		}
	}

	cout << ans;
	return 0;
}
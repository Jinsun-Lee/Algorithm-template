#include <iostream>
#include <tuple> // tie(y, x)
using namespace std;

bool isValid(int arr[9]) {
	bool chk[9] = {};
	for (int i = 0; i < 9; ++i) {
		chk[arr[i] - 1] = true;
	}
	for (bool b : chk) if (!b) return false;
	return true;
}

void getBlock(int map[9][9], int sy, int sx, int num[9]) {
	int idx = 0;
	for (int y = 0; y < 3; ++y) {
		for (int x = 0; x < 3; ++x) {
			num[idx++]=map[sy + y][sx + x];
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int tc; cin >> tc;
	int map[9][9], tmp[9];
	bool valid;

	for (int t = 1; t <= tc; ++t) {
		valid = true;

		// 입력
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				cin >> map[i][j];
			}
		}

		// 행/열
		for (int i = 0; i < 9 && valid; ++i) { // && valid
			if (!isValid(map[i])) valid = false; // 행

			for (int j = 0; j < 9; ++j) tmp[j] = map[j][i]; // 열, wh 주의
			if (!isValid(tmp)) valid = false;
		}

		// 3x3 블록 체크(9개의 정사각형에서 구역별로 9칸 탐색)
		for (int i = 0; i < 9 && valid; i += 3) {
			for (int j = 0; j < 9; j += 3) {
				getBlock(map, i, j, tmp);
				if (!isValid(tmp)){
					valid = false;
					break;
				}
			}
		}

		cout << "#" << t << " " << ((valid) ? 1 : 0) << "\n";
	}
	return 0;
}
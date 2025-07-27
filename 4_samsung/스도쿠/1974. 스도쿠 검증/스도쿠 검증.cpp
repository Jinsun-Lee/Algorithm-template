#include <iostream>
using namespace std;

int map[9][9];

bool hasAll(int arr[9]) {
	bool chk[9] = {};
	for (int i = 0; i < 9; ++i) {
		chk[arr[i]-1] = 1; // 숫자 다 있는지 
	}
	for (int i = 0; i < 9; ++i) {
		if (chk[i] == 0) return false;
	}
	return true;
}

void getBlock(int y, int x, int num[9]) {
	int idx = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			num[idx++] = map[y + i][x + j]; 
		} // ++idx로 하면 첫 인덱스가 1니까 실수하지 마
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; ++t) {

		// 입력 1 3 6 8 9번만 1
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j)
				cin >> map[i][j];
		}

		// 가로랑 세로
		bool isValid = true;
		for (int i = 0; i < 9 && isValid; ++i) {
			isValid = hasAll(map[i]); // -> 0행부터 확인
			if (!isValid) break; // 전부 없으면 멈춰

			int col[9];
			for (int j = 0; j < 9; ++j) col[j] = map[j][i];
			isValid = hasAll(col); // col로 전달, ji인 거 주의 
			if (!isValid) break;
		}

		// 3*3 블럭
		int num[9];
		for (int i = 0; i < 9 && isValid; i+=3) { // 3씩 키워야 해
			for (int j = 0; j < 9 && isValid; j+=3) {
				getBlock(i, j, num);
				isValid = hasAll(num);
				if (!isValid) break;
			}
		}

		cout << "#" << t << " " << isValid << "\n";
	}
	return 0;
}
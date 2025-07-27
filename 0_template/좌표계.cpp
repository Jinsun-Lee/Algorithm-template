#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);

	// 1. 입력
	int W, H, p, q;
	cin >> W >> H >> p >> q;

	vector<vector<int>> ori(H, vector<int>(W));   // (0,0)좌하 (w,h)우상 | 가로w세로h
	vector<vector<int>> trans(W, vector<int>(H)); // (0,0)좌상 (w,h)우하 | 가로h세로w


	// 2. 기존 좌표계

	// 입력 부분: 123456 -> 6
	for (int y = 0; y < H; ++y) {
		for (int x = 0; x < W; ++x) {
			cin >> ori[y][x];
		}
	}

	// 출력 부분
	for (int y = 0; y < H; ++y) {
		for (int x = 0; x < W; ++x) {
			cout << setw(2) << ori[y][x] << ' ';
		}
		cout << "\n";
	}

	// 특정 좌표
	cout << ori[p][q] << "\n\n";


	// 3. 새 좌표계

	// 입력 부분: 13 7 1 -> 6
	for (int y = 0; y < H; ++y) {
		for (int x = 0; x < W; ++x) {   // 범위 HW랑 변수 주의
			cin >> trans[x][H - y - 1]; // 90도 회전은 arr[j][M-i-1]로 똑같음
		}
	}

	// 출력 부분
	for (int y = 0; y < W; ++y) {
		for (int x = 0; x < H; ++x) {
			cout << setw(2) << trans[y][x] << ' ';
		}
		cout << "\n";
	}

	// 특정 좌표
	int pp = q;
	int qq = H - p - 1;
	cout << trans[pp][qq];

	return 0;
}
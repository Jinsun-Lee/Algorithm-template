#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 5;
int map[N][N];
bool vis[N][N];
unordered_map<int, pair<int, int>> pos; // 숫자랑 위치 매핑

int Bingo() {
	int cnt = 0;

	bool diag1 = true, diag2 = true;
	for (int i = 0; i < N; ++i) {
		if (!vis[i][i]) diag1 = false;
		if (!vis[i][4 - i]) diag2 = false;

		bool row = true, col = true;
		for (int j = 0; j < N; ++j) {
			if (!vis[i][j]) row = false;
			if (!vis[j][i]) col = false;
		}
		cnt += row + col;
	}
	cnt += diag1 + diag2;

	return cnt;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
			pos[map[i][j]] = { i, j };
		}
	}
	
	int num, y, x;
	for (int i = 1; i <= N*N; ++i) {
		cin >> num;
		tie(y, x) = pos[num];
		vis[y][x] = 1;

		if (Bingo() >= 3) {
			cout << i;
			break;
		}
	}
	return 0;
}
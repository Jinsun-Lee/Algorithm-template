#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

const int MX = 21;
int N, map[MX][MX], ans = INT_MIN;

void turnCW(int map[MX][MX]) {
	int tmp[MX][MX];
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) tmp[j][N - i - 1] = map[i][j];
	}
	memcpy(map, tmp, sizeof(tmp));
}

void turnCCW(int map[MX][MX]) {
	int tmp[MX][MX];
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) tmp[N - j - 1][i] = map[i][j];
	}
	memcpy(map, tmp, sizeof(tmp));
}

void mergeLeft(int map[MX][MX]) {
	queue<int> q;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			if (map[y][x] != 0) q.push(map[y][x]);
			map[y][x] = 0; // map은 0으로 갱신
		}

		int xx = 0, pre = 0;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			if (pre == 0) pre = cur; // 초기거나, 합쳐졌을 때
			else {
				if (pre == cur) {
					map[y][xx++] = pre * 2;
					pre = 0;
				}
				else { // pre가 0은 아닌데, 달라
					map[y][xx++] = pre;
					pre = cur;
				}
			}
		}
		if (pre != 0) map[y][xx] = pre;
	}
}

void dfs(int dep, int map[MX][MX]) {
	if (dep >= 5) {
		for (int i = 0; i < N; ++i) {
			ans = max(ans, *max_element(map[i], map[i] + N));
		}
		return;
	}

	for (int dir = 0; dir < 4; ++dir) {
		int backup[MX][MX];
		memcpy(backup, map, sizeof(backup));

		for (int i = 0; i < dir; ++i) turnCW(backup);
		mergeLeft(backup);
		for (int i = 0; i < dir; ++i) turnCCW(backup);
		dfs(dep + 1, backup);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) cin >> map[i][j];
	}

	dfs(0, map);
	cout << ans;
	return 0;
}
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

const int MX = 21;
int N, map[MX][MX], ans=INT_MIN;

void up(int map[MX][MX]) {
	queue<int> q;
	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			if (map[y][x] != 0) q.push(map[y][x]);
			map[y][x] = 0;
		}
		int idx = 0, pre = 0, nxt = 0;
		while (!q.empty()) {
			if (pre == 0) { pre = q.front(); q.pop(); }
			else { 
				nxt = q.front(); q.pop();
				map[idx][x] = pre;
				if (pre == nxt) { pre = 0; map[idx][x] += nxt; }
				else pre = nxt; 
				idx++;
			}
		}
		if (pre != 0) map[idx][x] = pre;
	}
}

void right(int map[MX][MX]) {
	queue<int> q;
	for (int y = 0; y < N; ++y) {	
		for (int x = N - 1; x >= 0; --x) {
			if (map[y][x] != 0) q.push(map[y][x]);
			map[y][x] = 0;
		}
		int idx = N - 1, pre = 0, nxt = 0;
		while (!q.empty()) {
			if (pre == 0) { pre = q.front(); q.pop(); }
			else {
				nxt = q.front(); q.pop();
				map[y][idx] = pre;
				if (pre == nxt) { pre = 0; map[y][idx] += nxt; }
				else pre = nxt;
				idx--;
			}
		}
		if (pre != 0) map[y][idx] = pre;
	}
}

void down(int map[MX][MX]) {
	queue<int> q;
	for (int x = 0; x < N; ++x) {
		for (int y = N - 1; y >= 0; --y) {
			if (map[y][x] != 0) q.push(map[y][x]);
			map[y][x] = 0;
		}
		int idx = N - 1, pre = 0, nxt = 0;
		while (!q.empty()) {
			if (pre == 0) { pre = q.front(); q.pop(); }
			else {
				nxt = q.front(); q.pop();
				map[idx][x] = pre;
				if (pre == nxt) { pre = 0; map[idx][x] += nxt; }
				else pre = nxt;
				idx--;
			}
		}
		if (pre != 0) map[idx][x] = pre;
	}
}

void left(int map[MX][MX]) {
	queue<int> q;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			if (map[y][x] != 0) q.push(map[y][x]);
			map[y][x] = 0;
		}
		int idx = 0, pre = 0, nxt = 0;
		while (!q.empty()) {
			if (pre == 0) { pre = q.front(); q.pop(); }
			else {
				nxt = q.front(); q.pop();
				map[y][idx] = pre;
				if (pre == nxt) { pre = 0; map[y][idx] += nxt; }
				else pre = nxt;
				idx++;
			}
		}
		if (pre != 0) map[y][idx] = pre;
	}
}

void comb(int dir, int map[MX][MX]) {
	if (dir == 0) up(map);
	else if (dir == 1) right(map);
	else if (dir == 2) down(map);
	else left(map);
}

void dfs(int dep, int map[MX][MX]) {
	if (dep >=5) {
		for (int i = 0; i < N; ++i) {
			ans = max(ans, *max_element(map[i], map[i] + N));
		}
		return;
	}

	int backup[MX][MX];
	memcpy(backup, map, sizeof(backup));

	for (int dir = 0; dir < 4; ++dir) {
		comb(dir, map);
		dfs(dep + 1, map);
		memcpy(map, backup, sizeof(backup));
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
		}
	}

	dfs(0, map);
	cout << ans;
	return 0;
}
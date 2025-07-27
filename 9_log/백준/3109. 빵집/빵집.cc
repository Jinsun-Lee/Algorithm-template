#include <iostream>
using namespace std;

const int N = 10'001, M=501;
int R, C, ans = 0;
bool vis[N][M];

const int dy[3] = {-1, 0, 1}; //⭐↗→↘ 순서 진짜 중요

void input() {
	cin >> R >> C;

	char map;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> map;
			if (map == 'x') vis[i][j] = 1; // 이미 감, 못 가
			//else if (map=='.') vis[i][j]=0; // 아직 안 간 곳
		}
	}
}

bool dfs(int y, int x) {
	vis[y][x] = true;

	if (x == C - 1) {
		ans++;
		return true;
	}

	for (int i = 0; i < 3; ++i) {
		int ny = y + dy[i];
		if (ny>=0 && ny<R && vis[ny][x+1]==0) {
			if ( dfs(ny, x+1) ) return true;
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	input(); 
	
	for (int i = 0; i < R; ++i) dfs(i, 0);
	cout << ans;

	return 0;
}
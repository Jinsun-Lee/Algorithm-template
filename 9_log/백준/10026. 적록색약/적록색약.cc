#include <iostream>
#include <utility>
#include <queue>

#define Y first
#define X second

using namespace std;

int N;

const int MX = 102;
char map[MX][MX];
bool visited[MX][MX];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

queue<pair<int, int>> tmp;

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y, x });

	while(!q.empty()){
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (visited[ny][nx]) continue;
			if (map[cur.Y][cur.X] != map[ny][nx]) continue;
			
			visited[ny][nx] = true;
			q.push({ ny, nx });
		}	
	}
}

int getCnt() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == false) {
				visited[i][j] = true;
				bfs(i, j);
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N;

	//string str;
	for (int i = 0; i < N; i++) {
		//cin >> str;
		for (int j = 0; j < N; j++) {
			//map[i][j] = str[j];
			cin >> map[i][j];
			if (map[i][j] == 'G') tmp.push({ i, j }); // 적록색약일 때 바꾸려고
		}
	}

	int normal = getCnt(); // 일반

	// 방문 초기화
	for (int i = 0; i < N; i++) fill(visited[i], visited[i] + N, false);

	// 초록이랑 빨강 구분 못하니, 초록을 빨강으로
	while (!tmp.empty()) {
		pair<int, int> cur = tmp.front();
		map[cur.Y][cur.X] = 'R';
		tmp.pop();
	}

	int abnormal = getCnt();

	cout << normal << " " << abnormal;
	
	return 0;
}
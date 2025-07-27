#include <iostream>
#include <utility>
#include <queue>

#define Y first
#define X second

using namespace std;

int N, M;

const int MX = 32;
int pre[MX][MX];
int post[MX][MX];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y, x });

	int preVal = pre[y][x];
	int postVal = post[y][x];
	pre[y][x] = postVal; // 

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (pre[ny][nx] == preVal) {
				pre[ny][nx] = postVal;
				q.push({ ny, nx });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> pre[i][j];
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> post[i][j];
		}
	}

	bool isFirst = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			
			if (pre[i][j] != post[i][j]) {

				if (isFirst) { // 두 숫자가 다른것이 처음으로 나오면
					bfs(i, j); // 이전의 숫자가 바뀐 상태
					isFirst = false;
				}
				else { // 이미 숫자가 바뀌었는데 다른 게 나오면 
					cout << "NO";
					return 0;
				}
			}		
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (pre[i][j] != post[i][j]) {
				cout << "NO";
				return 0;
			}
		}
	}

	cout << "YES";
	
	return 0;
}
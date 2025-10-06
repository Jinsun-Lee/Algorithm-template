#include <iostream>
#include <climits>
#include <queue>
using namespace std;

#define Y first
#define X second

const int dy[]= {-1, 0, 1, 0};
const int dx[]= {0, 1, 0, -1};

const int MX = 1002;

int n, m;
int map[MX][MX];
int dist[MX][MX];

queue<pair<int, int>> q;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> m >> n;
    
    queue<pair<int,int>> q;
	//bool already = true;
    
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];

			// 저장할 때부터 토마토가 익어있다면 안 봐도 되니까
			//if (already && map[i][j] == 0) already = false; 
			
			// 이후 확인하려고
			if(map[i][j]==0) dist[i][j] = -1; 
			
			// 그리고 1인 것만 볼래
			if (map[i][j] == 1) q.push({ i, j });
		}
	}
    
    /*
	if (already) { // 만약 안 익은 게 없었다면 걍 끝내도 되니까 
		cout << 0;
		return 0;
	}
	*/
    
	while (!q.empty()) {
		pair<int, int> cur = q.front();	q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if(dist[ny][nx]>=0) continue;
			dist[ny][nx]=dist[cur.Y][cur.X] +1;
			q.push({ny,nx});
		}
	}

	// 모두 익지 못하는 상황이면 -1, 아니면 모두 익을 때까지의 최소 날짜
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j]==-1) { // map[i][j]이 0인지는 확인 안 해도 돼
				cout << -1;
				return 0;
			}

			cnt = max(cnt, dist[i][j]);
		}
	}
	
	cout << cnt;
	return 0;
}

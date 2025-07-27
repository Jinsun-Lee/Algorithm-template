#include <iostream>
#include <climits>
#include <queue>

#define Y first
#define X second

using namespace std;

int n, m;

const int MX = 1002;
int map[MX][MX];
int dist[MX][MX];

int dy[]= {-1, 0, 1, 0};
int dx[]= {0, 1, 0, -1};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen_s(new FILE*,"input.txt","r",stdin);

	cin >> m >> n;
	//bool done = true;
	queue<pair<int,int>> q;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> map[i][j];
			if(map[i][j]==1) q.push({i,j});

			//dist[i][j] = INT_MAX;
			if(map[i][j]==0) dist[i][j] = -1;

			//if(done && map[i][j]==0) done = false;
		}
	}

	/*if(done){
		// 저장할 때부터 이미 모두 익어 있다면
		//cout << "0";
		//return 0;
	//}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(map[i][j]==1 && dist[i][j]==INT_MAX){
				bfs(i,j);
			}
		}
	}*/
	
	while(!q.empty()){
		pair<int,int> cur = q.front();
		q.pop();

		for(int i = 0; i < 4; i++){
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];

			if(ny <0 || nx < 0 || ny >=n || nx >= m) continue;
			
			//if(map[ny][nx]==0 && dist[ny][nx] == INT_MAX){
				//map[ny][nx]=1;
				//int newDist = dist[cur.Y][cur.X] +1;
				//if(dist[ny][nx]<newDist) continue;
				//dist[ny][nx]=newDist;

			if(dist[ny][nx]>=0) continue;
			dist[ny][nx]=dist[cur.Y][cur.X] +1;

			q.push({ny,nx});
		}
	}

	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			//if(map[i][j]==0){

			if (dist[i][j]==-1){
				cout << "-1";
				return 0;
			}
			
			cnt = max(cnt,dist[i][j]);
		}
	}

	cout << cnt;
	
	return 0;
}
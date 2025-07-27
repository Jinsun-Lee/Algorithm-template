#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int W,H;

//vector<vector<int>> map;
//vector<vector<bool>> visited;

int map[50][50];
bool visited[50][50];

int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct Node {
	int y;
	int x;
};

void bfs(int y, int x){
	queue<Node> q;
	q.push({y,x});
	visited[y][x] = true;

	while(!q.empty()) { //
		//int y = q.front().y;

		Node curr = q.front();
		q.pop();

		for(int i = 0; i < 8; i++){
			int ny = curr.y + dy[i];
			int nx = curr.x + dx[i];

			if(ny < 0 || nx < 0 || ny >= H || nx >= W)continue;

			if(map[ny][nx]==1 && !visited[ny][nx]){ // 
				q.push({ny,nx});
				visited[ny][nx]=true;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0); //
	cin.tie(NULL); //

	//freopen_s(new FILE*, "input.txt", "r", stdin);

	while(1){
		cin >> W >> H;
		if(W==0 && H==0) break; // if(!W && !H) break;

		//map = vector<vector<int>> (H, vector<int>(W,0)); //
		//visited = vector<vector<bool>> (H,vector<bool>(W,false)); //

		// reset
		for(int i = 0; i < H; i++) fill(visited[i],visited[i]+W,false);

		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				cin >> map[i][j];
			}
		}

		int ans = 0;
		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				if(map[i][j]==1 && !visited[i][j]){ //
					bfs(i, j); 
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}

	return 0;
}
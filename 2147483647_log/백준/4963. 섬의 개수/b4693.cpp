#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int W, H;

vector<vector<int>> map;
vector<vector<bool>> visited;

int dy[] = { -1,-1,0,1,1,1,0,-1 };
int dx[] = { 0,1,1,1,0,-1,-1,-1 };

struct Node {
	int y;
	int x;
};

void bfs(int y, int x) {
	queue<Node> q;
	q.push({ y,x });

	//visited[y][x] = true; //

	while (!q.empty()) {
		Node currentNode = q.front();
		q.pop();

		for (int i = 0; i < 8; i++) {
			int ny = currentNode.y + dy[i];
			int nx = currentNode.x + dx[i];

			if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue; // 

			/*
			if(map[ny][nx] == 0) continue;
			if(visited[ny][nx]) continue;

			visited[ny][nx] = true;
			q.push({ny,nx});
			*/

			if (map[ny][nx] == 1 && visited[ny][nx] == false) {
				visited[ny][nx] = true;
				q.push({ ny,nx });
			}

		}
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	while (1) {
		cin >> W >> H;
		if (W == 0 && H == 0) break; //

		map = vector<vector<int>>(H, vector<int>(W, 0)); // H W인 것 주의
		visited = vector<vector<bool>>(H, vector<bool>(W, false));

		for (int i = 0; i < H; i++) { // H W인 것 주의 (W H가 아님)
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
			}
		}

		//visited[0][0] = true; 여기 아니고 

		int ans = 0;
		for (int i = 0; i < H; i++) { // H W인 것 주의 (W H가 아님)
			for (int j = 0; j < W; j++) {
				if (map[i][j] == 1 && visited[i][j] == false) {

					visited[i][j] = true; // 여기에 추가해야 해

					bfs(i, j);
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}

	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<vector<int>> map;

struct Node{
	int y; 
	int x;
};

int bessieDist(int sy,int sx,int ey,int ex){
	int mapY = abs(sy-ey)+1;
	int mapX = abs(sx-ex)+1;

	map = vector<vector<int>>(mapY,vector<int>(mapX,INT_MAX));

	int dy[] = {-1,-1,0,1,1,1,0,-1};
	int dx[] = {0,1,1,1,0,-1,-1,-1};

	queue<Node> q;
	q.push({0,0});
	map[0][0]=1;

	while(!q.empty()){
		Node currentNode = q.front();
		q.pop();

		for(int i = 0; i < 8; i++){
			int ny = currentNode.y + dy[i];
			int nx = currentNode.x + dx[i];

			if(ny < 0 || nx < 0 || ny >= mapY || nx >= mapX) continue;

			int newDist = map[currentNode.y][currentNode.x] +1;
			if(map[ny][nx]<=newDist) continue;
			map[ny][nx] = newDist;

			q.push({ny,nx});
		}
	}

	int ans = 0;
	for(int i = 0; i < mapY; i++){
		for(int j = 0; j < mapX; j++){
			ans = max(ans,map[i][j]);
		}
	}
	return ans;
}

int daisyDist(int sy, int sx, int ey, int ex){
	int mapY = abs(sy-ey)+1;
	int mapX = abs(sx-ex)+1;

	map = vector<vector<int>>(mapY,vector<int>(mapX,INT_MAX));

	int dy[] = {-1,0,1,0};
	int dx[] = {0,1,0,-1};

	queue<Node> q;
	q.push({0, 0});
	map[0][0]=1;

	while(!q.empty()){
		Node currentNode = q.front();
		q.pop();

		for(int i = 0; i < 4; i++){
			int ny = currentNode.y + dy[i];
			int nx = currentNode.x + dx[i];

			if(ny < 0 || nx < 0 || ny >= mapY || nx >= mapX) continue;

			int newDist = map[currentNode.y][currentNode.x] +1;
			if(map[ny][nx]<=newDist) continue;
			map[ny][nx] = newDist;

			q.push({ny,nx});
		}
	}

	int ans = 0;
	for(int i = 0; i < mapY; i++){
		for(int j = 0; j < mapX; j++){
			ans = max(ans,map[i][j]);
		}
	}
	return ans;
}


int main(){
	int By,Bx,Dy,Dx,Jy,Jx;
	cin >> By >> Bx;
	cin >> Dy >> Dx;
	cin >> Jy >> Jx;

	int bessie = bessieDist(By, Bx, Jy, Jx);
	int daisy = daisyDist(Dy, Dx, Jy,Jx);

	if(bessie>daisy) cout << "daisy";
	else if(bessie<daisy) cout << "bessie";
	else if(bessie==daisy) cout << "tie";

	return 0;
}
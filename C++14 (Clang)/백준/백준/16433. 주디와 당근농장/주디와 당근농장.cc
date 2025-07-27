#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<vector<int>> map;
vector<vector<int>> dist;

struct Node{
	int y; 
	int x;
};

int main(){
	int N,x,y;
	cin >> N >> y >> x;

	map = vector<vector<int>> (N, vector<int> (N,INT_MAX));

	int dy[] = {-1, 0, 1, 0};
	int dx[] = {0, 1, 0, -1};

	queue<Node> q;
	y = y-1; x=x-1;
	q.push({y,x});
	map[y][x]=1;

	while(!q.empty()){
		Node currentNode = q.front();
		q.pop();

		for(int i = 0; i < 4; i++){
			int ny = currentNode.y + dy[i];
			int nx = currentNode.x + dx[i];

			if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

			int newDist = map[currentNode.y][currentNode.x] +1;
			if(map[ny][nx]<=newDist) continue;
			map[ny][nx] = newDist;

			q.push({ny, nx});
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(map[i][j]%2==0) cout << ".";
			else cout << "v";
			//cout << map[i][j];
		}
		cout <<"\n";
	}

	return 0;
}
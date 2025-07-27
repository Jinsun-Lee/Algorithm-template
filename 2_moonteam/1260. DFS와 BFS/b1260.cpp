#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> nodeList;
vector<bool> visited;

void dfs(int from) {
	visited[from] = true; //
	cout << from << " ";

	for (int i = 0; i < nodeList[from].size(); i++) { //
		int to = nodeList[from][i]; //
		if (visited[to]) continue;
		
		dfs(to);

	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start); //
	visited[start] = true;

	while (!q.empty()) {
		int now = q.front(); // 1
		q.pop(); // 앞에 것이 빠짐, 걍 pop back인데 큐라 그럼
		cout << now << " ";

		for (int i = 0; i < nodeList[now].size(); i++) { //
			int to = nodeList[now][i]; // 2 3 4
			if (visited[to]) continue;
			
			visited[to] = true; // 
			q.push(to); // 바로 실행되지 않고, 쌓아둠
		}
	}
}

void compare(vector<int>& node) {
	sort(node.begin(), node.end());
}

int main() {
	int tCase;
	freopen_s(new FILE*, "b1260.txt", "r", stdin);
	cin >> tCase;

	int N, M, V; // 1000 10000
	for (int i = 0; i < tCase; i++) {
		cin >> N >> M >> V;

		//int arr[N] = { 0, }; // 다른 값으로는 초기화 안 돼
		//int* arr = new int[N];
		
		int from, to;
		nodeList = vector<vector<int>> (N+1); // 세로만 정의해 두는 것이 안전, (N+1, vector<int> (N+1))로 하면 가로축도 전부 추가됨
		visited = vector<bool> (N+1, false);
		for (int j = 0; j < M; j++) {
			cin >> from >> to;
			nodeList[from].push_back(to);
			nodeList[to].push_back(from);
		}

		//sort(nodeList.begin(), nodeList.end()); // 잘못된 sort
		
		// 방법1
		/*for (int i = 0; i < nodeList.size(); i++) {
			sort(nodeList[i].begin(), nodeList[i].end());
		}*/

		// 방법2
		/*for (vector<int> &node : nodeList) {
			sort(node.begin(), node.end());
		}*/

		// 방법3 (방법4이랑 같음)
		/*
		for_each(nodeList.begin(), nodeList.end(), [](vector<int>& node) { sort(node.begin(), node.end()); } );
		*/

		// 방법4 (가독성이랑 유지보수가 좋아)
		for_each(nodeList.begin(), nodeList.end(), compare);

		dfs(V);
		cout << "\n";
		visited = vector<bool>(N + 1, false);
		bfs(V);
		cout << "\n";
	}

	return 0;
}
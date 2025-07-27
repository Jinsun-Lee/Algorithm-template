#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> nodeLists;
vector<bool> visited;

void dfs(int from) {
	//if (visited[from]) return;
	visited[from] = true;
	cout << from << " ";

	for (int i = 0; i < nodeLists[from].size(); i++) {
		int to = nodeLists[from][i];
		if (visited[to]) continue;
		//visited[to] = true;
		dfs(to);
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = true;
	cout << start << " ";

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < nodeLists[cur].size(); i++) {
			int to = nodeLists[cur][i];
			if (visited[to]) continue;
			visited[to] = true;
			cout << to << " ";
			q.push(to);
		}
	}
}

void compare(vector<int>& node) {//
	sort(node.begin(), node.end()); //
}

int main() {
	int N, M, V;
	int from, to;

    cin >> N >> M >> V;

    nodeLists = vector<vector<int>>(N+1);
    visited = vector<bool> (N+1, false);

    for (int i = 0; i < M; i++) {
        cin >> from >> to;
        nodeLists[from].push_back(to);
        nodeLists[to].push_back(from);
    }

    // sort
    for_each(nodeLists.begin(), nodeLists.end(), compare);

    dfs(V);
    cout << "\n";
    visited = vector<bool>(N + 1, false);
    bfs(V);
    cout << "\n";

	return 0;
}
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> nodeList;
vector<bool> visited;

void dfs(int start) {
	stack<int> st;
	st.push(start);

	while (!st.empty()) {
		int cur = st.top();
		st.pop();

		if (visited[cur]) continue;
		visited[cur] = true;

		for (int nxt : nodeList[cur]) {
			if (visited[nxt] == false) st.push(nxt);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	nodeList = vector<vector<int>>(n);
	visited = vector<bool>(n, false);

	// 리스트 구성
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (computers[i][j]==0 || i == j) continue;

			nodeList[i].push_back(j);
			// nodeList[j].push_back(i);
		}
	}

	for (int i = 0; i < n; i++) {
		if (visited[i] == false) {
			dfs(i);
			answer++;
		}
	}

	return answer;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int tCase; cin >> tCase;
	while (tCase--) {
		int n; cin >> n;

		// 입력 받기
		vector<vector<int>> computers(n, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> computers[i][j];
			}
		}

		int result = solution(n, computers);
		cout << result << "\n";
	}
	
	return 0;
}
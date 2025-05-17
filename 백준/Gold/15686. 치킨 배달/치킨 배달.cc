#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Node {
	int y, x;
};

int N, M, ans = INT_MAX;
vector<Node> home, chicken;

void dist(vector<Node>& selected) {
	int sum = 0;
	for (const auto& h : home) {
		int minn = 2*N; 
		for (const auto& c : selected) {
			minn = min(minn, abs(h.y-c.y) + abs(h.x-c.x));
		}
		sum += minn; 
	}
	ans = min(ans, sum);
}

void dfs(int idx, vector<Node>& selected) { 
	if (selected.size()==M) {
		dist(selected);
		return;
	}
	
	if (idx >= chicken.size()) return;

	dfs(idx + 1, selected);
	selected.push_back(chicken[idx]);
	dfs(idx + 1, selected);
	selected.pop_back(); 
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
    
	int tmp;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> tmp;
			if (tmp == 1) home.push_back({ i, j });
			else if (tmp == 2) chicken.push_back({ i, j });
		}
	}

	vector<Node> selected = {};
	dfs(0, selected);
	cout << ans;
	return 0;
}
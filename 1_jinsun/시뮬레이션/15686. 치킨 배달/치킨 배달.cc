#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int N, M, ans = INT_MAX;
struct Node { int y, x; };
vector<Node> home, chicken, selected;

int calDist(vector<Node>& selected) {
	int sum = 0;
	for (const auto& h : home) {
		int dist = 2 * N;
		for (const auto& c : selected) {
			dist = min(dist, abs(h.y - c.y) + abs(h.x - c.x));
			if (dist == 1) break;
		}
		sum += dist;
		if (sum >= ans) return INT_MAX;
	}
	return sum;
}

void dfs(int idx, vector<Node>& selected) {
	if ((int)selected.size() >= M) {
		ans = min(ans, calDist(selected));
		return;
	}

	if (idx >= (int)chicken.size()) return;

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
			if (tmp == 1) home.push_back({i, j});
			else if (tmp == 2) chicken.push_back({ i, j });
		}
	}

	dfs(0, selected);
	cout << ans;
	return 0;
}

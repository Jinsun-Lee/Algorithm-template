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

int calDist(const vector<Node>& selected) {
	int sum = 0;
	for (const auto& h : home) {
		int minn = INT_MAX;
		for (const auto& c : selected) {
			int dist = abs(h.y - c.y) + abs(h.x - c.x);
			minn = min(minn, dist);
			if (minn == 1) break; // 최소거리 나오면 탐색 불필요
		}
		sum += minn;
		if (sum >= ans) return INT_MAX; // 현재까지의 거리가 ans보다 크면 탐색 불필요
	}
	return sum;
}

void dfs(int idx, vector<Node>& selected) {
	if ((int)selected.size() == M) {
		int sum = calDist(selected);
		ans = min(ans, sum);
		return;
	}

	// 치킨집 다 보면 탐색 종료
	if (idx == (int)chicken.size()) return;

	// 남은 치킨집의 수가 부족할 경우
	if (selected.size() + ((int)chicken.size() - idx) < M) return;

	// 선택 안 할 경우
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

	// 1. 치킨집을 M개 고름
	vector<Node> selected = {};
	dfs(0, selected);
	cout << ans;
	return 0;
}
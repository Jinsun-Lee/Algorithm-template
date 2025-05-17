#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Node {
	int y, x;
};

int N, M, ans=INT_MAX;
vector<Node> home, chicken;

//void dist(const vector<Node>& home, const vector<Node>& chicken) { // const vector<Node>& home
void dist(vector<Node>& selected) {
	int sum = 0;
	for (const auto& h : home) {
		int minn = 2*N; //  집과 여러 치킨집 사이의 거리를 계산
		for (const auto& c : selected) {
			int tmp = abs(h.y-c.y) + abs(h.x-c.x);
			minn = min(minn, tmp);
		}
		sum += minn; // 각 집과 치킨최소거리 리턴
	}
	ans = min(ans, sum);
}

//void select(int dep, vector<Node>& chick, const vector<Node>& home, vector<Node>& selected) { // home은 const랑 &, 둘은 그냥 &
void dfs(int dep, vector<Node>& selected) { 
	//if (dep >= M && select.size()==M) {
	if (selected.size()==M) {
		dist(selected); // 2. 집과 전체 최소 거리 계산
		return;
	}
	
	//if (chick.empty()) return;
	if (dep >= chicken.size()) return;

	//Node chx = chick.front(); chick.pop_front(); // 벡터 시간복잡도 확인, 이거 몰랐음, pop_front 없음
	
	//dfs(dep, chick, home, selected); // 선택 안 할 경우
	dfs(dep+1, selected);

	//selected.push_back(chk);
	selected.push_back(chicken[dep]);
	dfs(dep + 1, selected);
	selected.pop_back(); // 있는게 맞나
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
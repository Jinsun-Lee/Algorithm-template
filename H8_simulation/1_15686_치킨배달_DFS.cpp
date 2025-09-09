#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, ans = 0x7fffffff;

struct Node { int y, x; };
vector<Node> home, chicken, selected;

void calDist(vector<Node>& selected) {
	int sum = 0;
    
	for (const auto& h : home) {
		int minDist = 2 * N;
        
		for (const auto& c : selected) {
			int dist = abs(h.y-c.y) + abs(h.x-c.x);
			minDist = min(minDist, dist);

			if (minDist == 1) break; // 최소거리 나오면 탐색 불필요
		}
        
		sum += minDist; 
        if (sum>=ans) return; // 현재까지의 거리가 ans보다 크면 탐색 불필요
	}
    
	ans = min(ans, sum);
}

void DFS(int idx, vector<Node>& selected) { 
	if (selected.size()==M) {
		calDist(selected);
		return;
	}
	
	if (idx == chicken.size()) return; // 치킨집 다 보면 탐색 종료
    if (selected.size() + (chicken.size() - idx) < M) return; // 남은 치킨집의 수가 부족할 경우
    
	DFS(idx + 1, selected); // 선택 안 할 경우
	selected.push_back(chicken[idx]);
	DFS(idx + 1, selected); // 선택 할 경우
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

	//vector<Node> selected = {}; // 전역으로 해야 0ms 나와
	DFS(0, selected);
    
	cout << ans;
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node { int y, x; };
vector<Node> home, chicken;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int N, M, tmp; cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> tmp;
			if (tmp == 1) home.push_back({ i, j });
			else if (tmp == 2) chicken.push_back({ i, j });
		}
	}
    
    int chickSize = chicken.size();
	vector<int> mask(chickSize, 1); 
	fill(mask.begin(), mask.begin() + chickSize - M, 0); //★시작+치킨집총개수-M, 0하면 뒤쪽 M개 1로 택표시 | 치킨집이 5, M=3이면 00011
    
    int ans = 0x7fffffff; // 모든 집과 치킨집 사이의 거리 최소
	do {
		int sum = 0; // 치킨집의 조합이 나온 상황에서, 거리의 합
        
		for (const auto& h : home) {
			int minDist = 2 * N; // 현재 집과 모든 치킨집과의 거리 최솟값
            
			for (size_t i = 0; i < chickSize; i++) {
				if (mask[i] == 0) continue; // 선택되지 않은 치킨집
                
				int dist = abs(h.y-chicken[i].y) + abs(h.x - chicken[i].x);
                minDist = min(minDist, dist);
			}
            
			sum += minDist; // 최소 거리값을 거리의 합에 반영
		}
        
		ans = min(ans, sum);
	} while (next_permutation(mask.begin(), mask.end()));
    
	cout << ans;
	return 0;
}

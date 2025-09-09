# 시뮬레이션
1. [⭐](https://github.com/Jinsun-Lee/Algorithm-template/discussions/36)1_[15686](https://www.acmicpc.net/problem/15686)_치킨배달: [DFS(더 좋음)](https://github.com/Jinsun-Lee/Algorithm-template/blob/master/H8_simulation/1_15686_DFS.cpp)랑 [next_permutation(주의)](https://github.com/Jinsun-Lee/Algorithm-template/blob/master/H8_simulation/1_15686_STL.cpp)로 풀어보기
2. [⭐](https://github.com/Jinsun-Lee/Algorithm-template/discussions/37)2_[18808](https://www.acmicpc.net/problem/18808)_스티커붙이기: 
3. [⭐](https://github.com/Jinsun-Lee/Algorithm-template/discussions/35)⭐⭐3_[15683](https://www.acmicpc.net/problem/15683)_감시: 
4. [⭐](https://github.com/Jinsun-Lee/Algorithm-template/discussions/38)⭐⭐4_[12100](https://www.acmicpc.net/problem/12100)_2048(Easy): 

<br><br>

N개 중에서 M개 선택 시, 앞에 M개가 0(선택)  
참고: [선택을 1로 하는 코드](https://github.com/Jinsun-Lee/Algorithm-template/blob/master/H8_simulation/1_15686_STL.cpp)
```cpp
vector<bool> mask(N, 1); // 011 → 101 → 110
fill(mask.begin(), mask.begin() + M, 0);
fill(mask.begin(), mask.end() + M - chickSize, 0); // 동일

do {
    if (mask[i]==0) 동작
} while (next_permutation(mask.begin(), mask.end())); 
```


<br>

[Cal 분리한 코드](https://github.com/Jinsun-Lee/Algorithm-template/blob/master/H8_simulation/1_15686_DFS.cpp)보다 느린 이유는?  
→ 아래 코드는 조합이 완성되면 전부 거리 계산하는데, 분리한 코드에서는 거리 계산이랑 조합 고를 때 가지치기해서 덜 계산해
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int minAns = 0x7fffffff;

struct pii { int y, x; };
vector<pii> home, chick, selec;

void DFS(int dep, vector<pii>& selec) {
	if (M == selec.size()) {
		int sum = 0;
		
		for (const auto& h : home) { // const 
			int minDist = 2 * N;

			for (const auto& c : selec) {
				int dist = abs(h.y - c.y) + abs(h.x - c.x);
				minDist = min(minDist, dist);

				if (minDist == 1) break; // 최소거리가 나오면 더이상 탐색 불필요
			}
			
			sum += minDist;
			if (sum >= minAns) return; // 현재까지의 거리가 ans보다 크면 탐색 불필요
		}
		minAns = min(minAns, sum);
		return;
	}

	if (dep == chick.size()) return;
	// if ((chick.size() - dep) + selec.size() < M) return;

	DFS(dep + 1, selec);
	selec.push_back(chick[dep]);
	DFS(dep+1, selec);
	selec.pop_back();
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;

	int t;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> t;
			if (t == 1) home.push_back({i, j});
			else if (t == 2) chick.push_back({i, j});
		}
	}

	//vector<pii> selec; // 전역으로 두라고 이자식아
	DFS(0, selec);

	cout << minAns;
	return 0;
}
```

<br>

```cpp

```

<br>

```cpp

```

<br>

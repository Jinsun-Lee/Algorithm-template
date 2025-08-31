#include <iostream>
#include <algorithm>
using namespace std;

int N, M, height[1'000'001]; // 나무의수, 가져갈길이, 나무의높이들

bool check(const int mid) {
	long long sum = 0;
	for (int h : height) if (h > mid) sum += (h - mid);
	return sum >= M;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> height[i];

	int st = 0, en = 1e9, mid;
	int ans;

	while (st <= en) {
		mid = st/2 + en/2 + (1&st&en); // (st+en)/2
		
		if (check(mid)) { // 성공조건
			ans = mid; 
			st = mid + 1; // st랑 en이 바뀔 수는 있어
		}
		else en = mid - 1;
	}
    
	cout << ans;
	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, A[1'000'001];
vector<int> uni;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		uni.push_back(A[i]);
	}

	// 정렬 필수 + 중복 제거
	sort(uni.begin(), uni.end());
	uni.erase(unique(uni.begin(), uni.end()), uni.end());

	// uni.begin()을 빼주면 A[i]가 등장하는 인덱스
	for (int i = 0; i < N; ++i) cout << lower_bound(uni.begin(), uni.end(), A[i]) - uni.begin() << " ";
	return 0;
}
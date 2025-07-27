#include <iostream>
#include <algorithm>
using namespace std;

int N, A[100'001];

int binarySearch(int target) {
	int st, en, mid;
	st = 0; en = N - 1;

	while (st <= en) { // 등호 주의
		mid = (st + en) / 2;
		
		if (A[mid] == target) return 1;
		else if (A[mid] < target) st = mid + 1;
		else if (A[mid] > target) en = mid - 1;
	
		// if (en < st) return 0; 별도로 없어도 돼
	}
    
	return 0; // en < st일 경우
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) cin >> A[i];
	sort(A, A+N);

	int M, target; cin >> M;
	for (int i = 0; i < M; ++i) {
		cin >> target;
		cout << binarySearch(target) << "\n";
	}
	return 0;
}
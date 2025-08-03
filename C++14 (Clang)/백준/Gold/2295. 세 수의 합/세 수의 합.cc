#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, a[1'001];
vector<int> two;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> a[i];
	sort(a, a + N);

	for (int i = 0; i < N; ++i) { // 두번째 범위 주의 
		for (int j = i; j < N; ++j) two.push_back(a[i] + a[j]);
	}
	sort(two.begin(), two.end());

	for (int i = N - 1; i > 0; --i) { // 0에 부등호 없고
		for (int j = 0; j < i; ++j) { // j < i야
			if (binary_search(two.begin(), two.end(), a[i] - a[j])) {
				cout << a[i];
				return 0;
			}
		}
	}
	return 0;
}
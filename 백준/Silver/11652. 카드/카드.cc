#include <iostream>
#include <algorithm>
using namespace std;
#define num first
#define freq second
long long arr[100000];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    
	int N; cin >> N;
	for (int i = 0; i < N; ++i) cin >> arr[i];
	sort(arr, arr + N);

	pair<long long, int> mx = {arr[0], 1};
	for (int i = 0; i < N - 1;) {
		int cur = i;
		while (i < N && arr[cur] == arr[i]) i++;
		int cnt = i - cur;
		if (mx.freq < cnt) mx = {arr[cur], cnt};
	}
	cout << mx.num;
	return 0;
}
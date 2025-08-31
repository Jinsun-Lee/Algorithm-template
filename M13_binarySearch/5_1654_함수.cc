#include <iostream>
using namespace std;

typedef long long ll;
int K, N, arr[10'001];

bool solve(ll x) { // 길이가 mid = x일 때 랜선이 N개가 나올 수 있는지
	ll cur = 0;
	for (int i = 0; i < K; ++i) cur += arr[i] / x;
	return cur >= N;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> K >> N;
	for (int i = 0; i < K; ++i) cin >> arr[i];
	//sort(arr, arr + K);

	ll st = 1;
	ll en = 0x7fffffff; // 2^31-1
	while (st < en) {
		ll mid = (st + en + 1) / 2;
		if (solve(mid)) st = mid;
		else en = mid - 1;
	}
	cout << st;
	return 0;
}
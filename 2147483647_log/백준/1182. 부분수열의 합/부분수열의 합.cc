#include <iostream>
using namespace std;

int n, s;
int cnt = 0;

const int MX = 21;
int arr[MX];
//bool visit[MX];

void chk(int depth, int sum) {
	// 포함되지 않아도 depth+1이기 때문에 if if로 쓰는 것이 맞음
	if (n == depth) {
		if (sum == s) cnt++;
		return;
	}

	/* 이 코드는 시간 초과
	for (int i = 0; i < n; i++) {
		if (visit[i]) continue;

		visit[i] = 1;
		sum += arr[i];
		chk(depth + 1, sum);
		visit[i] = 0;
		sum -= arr[i];
	*/
    
	chk(depth + 1, sum);
	chk(depth + 1, sum+arr[depth]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];
	chk(0, 0);

	if (s == 0) cnt--;

	cout << cnt;
	return 0;
}
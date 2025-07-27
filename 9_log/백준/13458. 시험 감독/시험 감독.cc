#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int n; // 시험장의 수
	cin >> n;

	int tmp;
	vector<int> a; // 응시자의 수
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		a.push_back(tmp);
	}

	int b, c; // 총감, 부감
	cin >> b >> c;

	long long ans = 0;

	// 각 시험장에 대한 감독관 수 계산
	for (int i = 0; i < n; i++) {

		a[i] -= b; ans++;
		if (a[i] <= 0) continue;

		ans += a[i] / c;
		if (a[i] % c) ans++;
        
	}

	cout << ans;

	return 0;
}
#include <iostream>

using namespace std;

int d[1000001]{ 0, 1 };
const int m = 1000000007;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	
	for (int i = 2; i <= N; i++) {
		d[i] = (d[i - 1] + d[i - 2]) % m;
	}

	cout << d[N];

	return 0;
}
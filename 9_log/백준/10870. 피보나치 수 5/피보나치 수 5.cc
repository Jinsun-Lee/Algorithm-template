#include <iostream>

using namespace std;
using ll = long long;

int d[91]{ 0 };
int fibo(int n) {
	if (n < 2) return n;
	if (d[n] != 0) return d[n];
	d[n] = fibo(n - 1) + fibo(n - 2);
	return d[n];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	cout << fibo(N);
	
	return 0;
}
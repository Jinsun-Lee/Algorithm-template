#include <iostream>

using namespace std;

int factorial(int n) {
	if (n < 2) {
		return 1;
	}
	return n * factorial(n - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	cout << factorial(N);
	
	return 0;
}
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tmp;
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		cin >> tmp;
		sum += (tmp * tmp);
	}
	cout << sum %10;
	return 0;
}
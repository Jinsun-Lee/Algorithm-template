#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int n;
	cin >> n;

	for (int star = n; star > 0; star--) {
		for (int i = n - star; i > 0; i--) cout << " ";
		for (int j = 0; j < star; j++) cout << "*";
		cout << "\n";
	}

	return 0;
}
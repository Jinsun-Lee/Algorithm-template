#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int minS = 0, manS = 0, tmp;
	for (int i = 0; i < 8; i++) {
		cin >> tmp;
		if (i < 4) minS += tmp;
		else manS += tmp;
	}

	cout << max(minS, manS);

	return 0;
}
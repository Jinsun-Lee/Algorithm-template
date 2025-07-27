#include <iostream>

using namespace std;

int card[21];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	for (int i = 1; i <= 20; i++) card[i] = i;

	int a, b, tmp;
	for (int i = 0; i < 10; i++) { // 구간이 10개 주어짐
		cin >> a >> b;

		for (int i = 0; i <= (b - a) / 2; i++) {
			swap(card[a + i], card[b - i]);
		}
	}

	for (int i = 1; i <= 20; i++) cout << card[i] << " ";

	return 0;
}
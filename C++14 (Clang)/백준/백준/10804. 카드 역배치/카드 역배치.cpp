#include <iostream>
#include <algorithm>

using namespace std;

int card[21];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);

	for (int i = 1; i <= 20; i++) card[i] = i;

	int a, b;
	for (int i = 1; i <= 10; i++) { // 구간이 10개 주어짐
		cin >> a >> b;

		/*
		for (int i = 0; i < (b-a+1) / 2; i++) {
			swap(card[a + i], card[b - i]);
		}
		*/

		// stl 사용, 위와 동일하게 동작
		reverse(card + a, card + b + 1); // a부터 b전까지라 b를 포함하기 위해 +1을 함
	}

	for (int i = 1; i <= 20; i++) cout << card[i] << " ";

	return 0;
}
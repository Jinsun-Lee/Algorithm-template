#include <iostream>
#include <algorithm> // 백준에서는 이거 있어야 됨

using namespace std;

int num[9];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	for (int i = 0; i < 9; i++) cin >> num[i];
	cout << *max_element(num, num + 9) << "\n"; // 값
	cout << max_element(num, num + 9) - num + 1; // 인덱스는 전체 주소-시작주소(num) / for가 0부터라 +1

	return 0;
}
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void hanoi(int a, int b, int n) {
	if (n == 1) { // 432 계속요청되다가 가장위의링 1번기둥에서 b번 기둥으로 이동
		cout << a << ' ' << b << '\n';
		return;
	}
	
	hanoi(a, 6 - a - b, n - 1); // 기둥a에서 기둥b로 n-1개옮기기

	cout << a << ' ' << b << '\n';
	hanoi(6 - a - b, b, n - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k; // 링의 수
	cin >> k;

	//cout << (1 << k) - 1 << '\n'; // 총 2^k-1번 이동이 필요

	//n이 너무 커서 출력만 수정
	string a = to_string(pow(2, k));
	int x = a.find('.'); //pow 함수 결과가 실수형이기에 소수점 찾기
	a = a.substr(0, x); //소수점 앞자리만 나오게하기
	a[a.length() - 1] -= 1;
	cout << a << "\n";

	if (k<=20) hanoi(1, 3, k); // 기둥1에서 기둥3으로 링k개옮기기
	
	return 0;
}
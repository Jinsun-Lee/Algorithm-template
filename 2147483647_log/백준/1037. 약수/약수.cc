#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int num;            // 약수의 개수
	int divisor[50];    // 약수
	int N = 0;          // 입력받은 약수를 가진 정수  

	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> divisor[i];
	}

	sort(divisor, divisor + num);

	// 약수들 중 가장 작은 값 x 가장 큰 값을 해주면 N
	N = divisor[0] * divisor[num - 1];
	cout << N;

	return 0;
}
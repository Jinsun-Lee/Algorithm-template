#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int A, B, V; cin >> A >> B >> V;
	
	// ceil(a / b)은 정수형에서는 (a + b - 1) / b로 계산 가능
	int a = (V - B);
	int b = (A - B);
	cout << (a + b - 1) / b;
	return 0;
}
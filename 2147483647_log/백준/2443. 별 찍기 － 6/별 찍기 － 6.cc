#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int n;
	cin >> n;

    for (int i = 0; i < n; i++) {
	    for (int k = 0; k < i; k++) cout << " "; // 4번 문제 사용
    	for (int j = 0; j < n-i; j++) cout << "*"; // 4번 문제 사용
	    for (int l = 0; l < n-i-1; l++) cout << "*"; // 3번 문제 사용
	    cout << "\n";
    }

	return 0;
}
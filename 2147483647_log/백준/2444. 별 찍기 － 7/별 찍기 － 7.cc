#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int n;
	cin >> n;

    // 5번 6번 합쳐도 되네...
    for (int i = 1; i <= n-1; i++) { // 여기에서 마지막 줄만 빼기
    	for (int k = 1; k <= n - i; k++) cout << " "; 
    	for (int j = 1; j <= 2 * i - 1; j++) cout << "*"; 
    	cout << "\n";
    }
    for (int i = n; i >= 1; i--) { 
    	for (int k = 1; k <= n - i; k++) cout << " ";
    	for (int j = 1; j <= 2 * i - 1; j++) cout << "*";
    	cout << "\n";
    }

	return 0;
}
#include <iostream>

using namespace std;

void func1(int n) {
	/*
	*
	**
	***
	****
	*****
	*/

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) cout << "*";
		cout << "\n";
	}

	return;
}

void func2(int n) {
	/*
		*
	   **
	  ***
	 ****
	*****
	*/

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n-i-1; k++) cout << " "; // 등호 없어야 해
		for (int j = 0; j <= i; j++) cout << "*";
		cout << "\n";
	}

	return;
}

void func3(int n) {
	/*
	*****
	****
	***
	**
	*
	*/

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n - i; k++) cout << "*"; // -1을 제거
		//for (int j = 0; j <= i; j++) cout << "*";
		cout << "\n";
	}

	return;
}

void func4(int n) {
	/*
	*****
	 ****
	  ***
	   **
		*	
	*/

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < i; k++) cout << " "; // 2번에서 위아래 조건 바꾸고, 등호 제거
		for (int j = 0; j < n - i; j++) cout << "*";
		cout << "\n";
	}

	return;
}

void func5(int n) {
	/*
		*
	   ***
	  *****
	 *******
	*********
	*/

	/*
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n - i - 1; k++) cout << " "; 
		for (int j = 0; j <= i; j++) cout << "*";
		for (int l = 0; l < i; l++) cout << "*"; // 2번에 추가 출력
		cout << "\n";
	}
	*/
	
	for (int i = 1; i <= n; i++) { // 범위
		for (int k = 1; k <= n - i; k++) cout << " "; // 
		for (int j = 1; j <= 2 * i - 1; j++) cout << "*"; //
		cout << "\n";
	}

	return;
}

void func6(int n) {
	/*
	*********
	 *******
	  *****
	   ***
		*
	*/

	/*
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < i; k++) cout << " "; // 4번 문제 사용
		for (int j = 0; j < n-i; j++) cout << "*"; // 4번 문제 사용
		for (int l = 0; l < n-i-1; l++) cout << "*"; // 3번 문제 사용
		cout << "\n";
	}
	*/

	for (int i = n; i >= 1; i--) { // 5번에서 여기만 바꾸기
		for (int k = 1; k <= n-i; k++) cout << " ";
		for (int j = 1; j <= 2*i-1; j++) cout << "*";
		cout << "\n";
	}

	return;
}

void func7(int n) {
	/*
		*
	   ***
	  *****
	 *******
	*********
	 *******
	  *****
	   ***
		*
	*/

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

	return;
}

void func8(int n) {
	/*
	*        *
	**      **
	***    ***
	****  ****
	**********
	****  ****
	***    ***
	**      **
	*        *
	*/

	// 1 2 3 4 붙이고 아래의 for문에서 첫 줄만 제거, 그리고 범위 변경
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) cout << "*";
		for (int k = 1; k <= 2*(n-i); k++) cout << " ";
		for (int j = 1; j <= i; j++) cout << "*";
		cout << "\n";
	}
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n - i; k++) cout << "*";
		for (int k = 1; k <= 2*i; k++) cout << " ";
		for (int j = 1; j <= n - i; j++) cout << "*";
		cout << "\n";
	}
	
	return;
}

void func9(int n) {
	/*
	*********
	 *******
	  *****
	   ***
		*
	   ***
	  *****
	 *******
	*********
	*/
	
	/*
	for (int i = n; i > 1; i--) {
		for (int k = 1; k <= n-i; k++) cout << " ";
		for (int j = 1; j <= 2*i-1; j++) cout << "*";
		cout << "\n";
	}
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n-i; k++) cout << " ";
		for (int j = 1; j <= 2*i-1; j++) cout << "*";
		cout << "\n";
	}
	*/

	for (int i = 0; i < n-1; i++) {
		for (int k = 0; k < i; k++) cout << " ";
		for (int j = 0; j < 2 * (n-i)-1; j++) cout << "*";
		cout << "\n";
	}
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n - i; k++) cout << " ";
		for (int j = 1; j <= 2 * i - 1; j++) cout << "*";
		cout << "\n";
	}

	return;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int n;
	cin >> n;

	func9(n);

	return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 여기를 이렇게 바꾸고 메모리 -5000, 시간 -600
	string d[10001], ans, a, b;
	int n, sum, carry =  0; 
	cin >> n;
	
	d[0] = "0";
	d[1] = "1";

	for (int i = 2; i <= n; i++) {
		a = d[i - 1];
		b = d[i - 2];

		ans = "";
		carry = 0;

		// 여기를 이렇게 바꾸고 시간 -10
		while (a.length() > b.length())
			b.insert(0, "0");

		// 여기를 이렇게 바꾸고 
		for (int j = a.length() - 1; j >= 0; j--) {
			sum = carry + (a[j] - '0') + (b[j] - '0');

			carry = sum / 10; // 올림수
			ans += sum % 10 + '0'; // 현재 자리수
		}

		if (carry) ans += "1";

		reverse(ans.begin(), ans.end());
		d[i] = ans;
	}

	cout << d[n];

	return 0;
}
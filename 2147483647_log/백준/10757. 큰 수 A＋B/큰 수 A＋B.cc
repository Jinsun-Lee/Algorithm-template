#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a, b;
	cin >> a >> b;
	
	int lenA = a.length();
	int lenB = b.length();

	// 큰 수로 자리수 맞춰주기
	int maxLen = max(lenA, lenB);
	a = string(maxLen - lenA, '0') + a;
	b = string(maxLen - lenB, '0') + b;

	string ans = "";
	int carry = 0; // 올림
	for (int i = maxLen - 1; i >= 0; i--) {
		int digitSum = carry + (a[i] - '0') + (b[i] - '0');
		carry = digitSum / 10; // 올림
		//ans = ans + to_string(digitSum % 10);
		ans += (digitSum % 10) + '0';
	}

	// 마지막에도 올리는 수가 있다면 추가
	if (carry > 0) ans += (carry + '0');

	reverse(ans.begin(), ans.end());
	cout << ans;

	return 0;
}
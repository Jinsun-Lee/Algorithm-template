#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int tCase;
	cin >> tCase;

	int ans = 0;

	while (tCase--) {
		string str;
		cin >> str;

		stack<char> st;

		//for (int i = 0; i < str.length(); i++) {
		for (auto c : str){

			if (!st.empty() && st.top() == c) st.pop(); // 비어있지 않고, 이전것과 같으면 빼고
			else st.push(c); // 아니면 추가
		}

		if (st.empty()) ans++;
	}

	cout << ans;
	return 0;
}
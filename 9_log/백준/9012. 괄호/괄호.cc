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

	while (tCase--) {
		string str;
		cin >> str;

		stack<char> st;
		bool isValid = true;

		for (auto c : str){

			if (isValid == false) break;

			if (!st.empty() && c == ')' && st.top() == '(') {
				st.pop();
				continue;
			}
			
			st.push(c); // ( 추가
		}

		if (!st.empty()) isValid = false;
		cout << (isValid ? "YES" : "NO") << "\n";
	}

	return 0;
}
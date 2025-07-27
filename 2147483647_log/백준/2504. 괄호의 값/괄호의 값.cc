#include <iostream>
#include <stack>
#include <string>

using namespace std;

string str;
stack<char> st;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> str;

	int sum = 0; // 누적해서 더해질 값
	int num = 1; // 곱해질 값

	for (int i = 0; i < str.size(); i++) {
		
		char c = str[i];

		if (c == '(') {
			num *= 2; //
			st.push(c);
		}

		else if (c == '[') {
			num *= 3;
			st.push(c);
		}

		else if (c == ')') {
			if (st.empty() || st.top() != '(') {
				cout << 0;
				return 0;
			}
			if (str[i - 1] == '(') sum += num; // 직전 괄호가 여는 괄호였다면 sum에 값 추가
			num /= 2; // 소괄호 쌍이 사라졌으니 2로 나눔      
			st.pop();
		}

		else { // c == ']'
			if (st.empty() || st.top() != '[') {
				cout << 0;
				return 0;
			}
			if (str[i - 1] == '[') sum += num;
			num /= 3;
			st.pop();
		}

	}

	//cout << (isValid ? "yes" : "0");
	if (st.empty()) cout << sum;
	else cout << 0;

	return 0;
}
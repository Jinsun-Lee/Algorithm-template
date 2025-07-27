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

	int sum = 0; 

	for (int i = 0; i < str.length(); i++) {
		
		char c = str[i];

		if (c == '(') {
			st.push(c);
		}

		else { // )일 경우

			if (str[i - 1] == '(') { // ()로 레이저일 경우
				st.pop(); // 막대인 줄 알고 추가했기 때문에 제거하고
				sum += st.size(); // 막대의 개수를 추가
			}

			else { // 막대의 끝일 경우
				st.pop(); // 막대를 하나 감소하고
				sum++; // 막대 1개가 절단된 것과 동일한 상황이기 때문에 추가
			}
		}

	}

	cout << sum;

	return 0;
}
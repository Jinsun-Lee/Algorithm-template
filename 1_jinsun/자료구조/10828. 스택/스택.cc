#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int n;
	cin >> n;

	stack<int> st; // 
	while (n--) {
		string c;
		cin >> c;

		if (c == "push") {
			int t;
			cin >> t;
			st.push(t);
		}

		else if (c == "pop") {
			if (!st.empty()) {
				cout << st.top() << "\n";
				st.pop();
			}
			else cout << "-1\n";
		}

		else if (c == "size") {
			cout << st.size() << "\n";
		}

		else if (c == "empty") {
			if (!st.empty()) cout << "0\n";
			else cout << "1\n";
		}

		else {
			if (!st.empty()) cout << st.top() << "\n";
			else cout << "-1\n";
		}
        
	}

	return 0;
}
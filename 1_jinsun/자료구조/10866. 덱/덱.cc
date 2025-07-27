#include <iostream>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int n;
	cin >> n;

	deque<int> deq;

	while (n--) {
		string c;
		cin >> c;

		if (c == "push_front") {
			int t;
			cin >> t;
			deq.push_front(t);
		}

		else if (c == "push_back") {
			int t;
			cin >> t;
			deq.push_back(t);
		}

		else if (c == "pop_front") {
			if (deq.empty()) cout << "-1" << "\n";
			else {
				cout << deq.front() << "\n";
				deq.pop_front();
			}
		}

		else if (c == "pop_back") {
			if (deq.empty()) cout << "-1" << "\n";
			else {
				cout << deq.back() << "\n";
				deq.pop_back();
			}
		}

		else if (c == "size") cout << deq.size() << "\n";

		else if (c == "empty") cout << (deq.empty()) << "\n";

		else if (c == "front") {
			if (deq.empty()) cout << "-1" << "\n";
			else cout << deq.front() << "\n";
		}

		else {
			if (deq.empty()) cout << "-1" << "\n";
			else cout << deq.back() << "\n";
		}

	}

	return 0;
}
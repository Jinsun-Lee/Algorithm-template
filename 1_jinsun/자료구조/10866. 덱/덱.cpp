#include <iostream>

using namespace std;

const int MX = 1000005;
int dat[2 * MX + 1];
int head = MX, tail = MX;

void push_front(int x) {
	dat[--head] = x; // dat[head--] 아님
}

void push_back(int x) {
	dat[tail++] = x;
}

void pop_front() {
	head++;
}

void pop_back() {
	tail--;
}

int front() {
	return dat[head];
}

int back() {
	return dat[tail - 1];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int n;
	cin >> n;

	while (n--) {
		string c;
		cin >> c;

		if (c == "push_front") {
			int t;
			cin >> t;
			push_front(t);
		}

		else if (c == "push_back") {
			int t;
			cin >> t;
			push_back(t);
		}

		else if (c == "pop_front") {
			if (tail == head) cout << "-1" << "\n";
			else {
				cout << front() << "\n";
				pop_front();
			}
		}

		else if (c == "pop_back") {
			if (tail == head) cout << "-1" << "\n";
			else {
				cout << back() << "\n";
				pop_back();
			}
		}

		else if (c == "size") cout << tail - head << "\n";

		else if (c == "empty") cout << (int)(tail == head) << "\n";

		else if (c == "front") {
			if (tail == head) cout << "-1" << "\n";
			else cout << front() << "\n";
		}

		else {
			if (tail == head) cout << "-1" << "\n";
			else cout << back() << "\n";
		}

	}

	return 0;
}
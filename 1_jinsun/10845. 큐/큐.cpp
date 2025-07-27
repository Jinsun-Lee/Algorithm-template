#include <iostream>

using namespace std;

const int MX = 1000005;
int dat[MX];
int head = 0;
int tail = 0;

void push(int val) {
	dat[tail++] = val;
}

void pop() {
	head++;
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
		string q;
		cin >> q;

		if (q == "push") {
			int t; cin >> t;
			push(t);
		}

		else if (q == "pop") {
			if (tail == head) cout << "-1" << "\n";
			else {
				cout << front() << "\n";
				pop();
			}
		}

		else if (q == "size") cout << tail - head << "\n";

		else if (q == "empty") cout << (int)(tail == head) << "\n";

		else if (q == "front") {
			if (tail == head) cout << "-1" << "\n";
			else cout << front() << "\n";
		}

		else { // back
			if (tail == head) cout << "-1" << "\n";
			else cout << back() << "\n";
		}

	}
	return 0;
}
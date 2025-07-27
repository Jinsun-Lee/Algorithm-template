#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	while (!cin.eof()) {
		getline(cin, s);
		cout << s << "\n";
	}

	return 0;
}
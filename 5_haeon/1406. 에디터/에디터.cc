#include <iostream>
#include <list>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	string str;
	cin >> str;

	//list<char> L(str.begin(), str.end()); //
	list<char> L;
	for (auto c : str) L.push_back(c);

	//list<char>::iterator t = L.end(); //
	auto cusor = L.end();

	int tCase;
	cin >> tCase;
	while (tCase--) { //
		char oper;
		cin >> oper;

		switch (oper) {
			case 'L':
				if (cusor != L.begin()) cusor--; //
				continue;

			case 'D':
				if (cusor != L.end()) cusor++; //
				continue;

			case 'B':
				if (cusor != L.begin()) {//
					cusor--;
					cusor = L.erase(cusor);
				}
				continue;

			case 'P':
				cin >> oper;
				L.insert(cusor, oper); //
				continue;
		}
	}

	for (auto c : L) cout << c; //

	return 0;
}
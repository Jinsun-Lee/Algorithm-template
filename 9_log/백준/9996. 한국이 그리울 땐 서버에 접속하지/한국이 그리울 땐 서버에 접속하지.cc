#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t; cin >> t;
	string str;	cin >> str;
    
	int index = str.find('*');
	string p1 = str.substr(0, index); // 앞쪽
	string p2 = str.substr(index+1); // index부터 끝까지 슬라이싱
	
	string s;
	for (int i = 0; i < t; i++) {
		cin >> s;

		if (s.size() < p1.length() + p2.length()) {
			cout << "NE\n";
			continue;
		}

		string a = s.substr(0, p1.length());
		string b = s.substr(s.length()-p2.length(), s.length());

		if (p1==a && p2==b) cout << "DA\n";
		else cout << "NE\n";
	}

	return 0;
}
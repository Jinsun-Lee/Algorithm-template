#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen_s(new FILE*,"input.txt","r",stdin);
	
	string a, b, c;
	cin >> a>>b>>c;

	cout << stoi(a) + stoi(b) - stoi(c) << "\n";
	cout << stoi(a + b) - stoi(c);

	return 0;
}
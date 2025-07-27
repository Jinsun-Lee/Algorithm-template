#include <iostream>
#include <string>

using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen_s(new FILE*, "input.txt", "r", stdin);

	ll n, ans=1;
	for (int i = 0; i < 3; i++) {
		cin >> n;
		ans *= n;
	}

	int cnt[10]{ 0 };

	string str = to_string(ans);
	//for (int i = 0; i < str.length(); i++) {
	for(char c: str){
		cnt[c - '0']++;
	}

	for (int i = 0; i < 10; i++) cout << cnt[i] << "\n";
	
	return 0;
}
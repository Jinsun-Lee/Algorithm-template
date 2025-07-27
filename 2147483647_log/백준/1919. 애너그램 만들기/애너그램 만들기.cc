#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen_s(new FILE*, "input.txt", "r", stdin);
	
	string s1, s2;
	cin >> s1 >> s2;

	int cnt[26]{ 0 };
	
	for (auto c : s1) cnt[c - 'a']++;
	for (auto c : s2) cnt[c - 'a']--;

	int ans = 0;
	for (int i = 0; i < 26; i++) {
		ans += abs(cnt[i]);
	}

	cout << ans;

	return 0;
}
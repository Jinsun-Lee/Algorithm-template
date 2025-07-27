#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int n;
	cin >> n;
	
	while (n--) {
		int cnt[26]{ 0 };
		string s1, s2;

		cin >> s1 >> s2;
		for (auto c : s1) cnt[c - 'a']++;

		bool isValid = true;
		for (auto c : s2) {
			cnt[c - 'a']--;
			if (cnt[c - 'a'] < 0) {
				isValid = false;
				break;
			}
		}

		if (isValid) {
			for (int i = 0; i < 26;i++) {
				if (cnt[i] != 0) {
					isValid = false;
					break;
				}
			}
		}

		cout << (isValid ? "Possible" : "Impossible") << "\n";
	}

	return 0;
}
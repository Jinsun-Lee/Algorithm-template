#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen_s(new FILE*, "input.txt", "r", stdin);

	string str;
	cin >> str;

	int cnt[10]{0};

	for (char c : str) {
		cnt[c - '0']++;
	}

	int tmp = cnt[6] + cnt[9];
	cnt[6] = tmp / 2;
	cnt[9] = tmp - cnt[6];

	cout << *max_element(cnt, cnt + 10);


	return 0;
}
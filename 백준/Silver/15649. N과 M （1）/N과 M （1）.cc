#include <iostream>
using namespace std;

int n, m;
bool visited[9];

void chk(int depth, string result) {
	// m 자리수까지만 돌게
	if (m <= depth) {
		for (char c : result) cout << c << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;

		result += (i+'0');
		visited[i] = 1;
		chk(depth + 1, result);
		result.pop_back();
		visited[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	chk(0, "");

	return 0;
}
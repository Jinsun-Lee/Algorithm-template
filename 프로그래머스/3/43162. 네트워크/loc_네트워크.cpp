#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen_s(new FILE*, "input.txt", "r", stdin);

	int tCase; cin >> tCase;
	while (tCase--) {
		int n; cin >> n;

		// 입력 받기
		vector<vector<int>> computers(n, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> computers[i][j];
			}
		}

		int result = solution(n, computers);
		cout << result << "\n";
	}
	
	return 0;
}
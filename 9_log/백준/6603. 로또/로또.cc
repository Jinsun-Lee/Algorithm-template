#include <iostream>
using namespace std;

int K, num[14];
int ans[6];

void dfs(int depth, int start) {
	if (depth >= 6) { 
		for (int i = 0; i < 6; ++i){
            cout << ans[i] << " ";
        }
		cout << "\n";
		return;
	}

	for (int i = start; i < K; ++i) {
		ans[depth] = num[i];
		dfs(depth + 1, i+1);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	while (cin >> K) {
		if (K == 0) break;
		else {
			for (int i = 0; i < K; ++i) cin >> num[i];
			dfs(0, 0);
			cout << "\n";
		}
	}
	return 0;
}
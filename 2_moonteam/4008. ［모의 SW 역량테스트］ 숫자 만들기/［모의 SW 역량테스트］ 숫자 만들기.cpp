#include <iostream>
#include <algorithm>
using namespace std;

string oper = "+-*/";
int N, operCnt[4], num[12], minn, maxx;

int cal(char op, int a, int b) {
	switch (op) {
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return a / b;
	}
}

void dfs(int dep, string result) {
	if (dep >= N-1) { // 부등호는 숫자보다 1 적어서
		int prev = num[0];
		for (int i = 1; i < N; ++i) {
			prev = cal((char)result[i-1], prev, num[i]);
		}
		minn = min(minn, prev);
		maxx = max(maxx, prev);
		return;
	}

	for (int i = 0; i < 4; ++i) { // 4가 맞아
		if (operCnt[i] == 0) continue;
		operCnt[i]--;
		dfs(dep + 1, result+oper[i]);
		operCnt[i]++;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		cin >> N;
		for (int i = 0; i < 4; ++i) cin >> operCnt[i];
		for (int i = 0; i < N; ++i) cin >> num[i];
		minn = 100000001, maxx = -100000001;
		dfs(0, "");
		cout << "#" << t << " " << maxx-minn << "\n";
	}
	return 0;
}
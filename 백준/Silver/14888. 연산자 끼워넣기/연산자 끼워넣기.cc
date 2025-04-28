#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

int N;
string oper = "+-*%";
int num[12], operCnt[4];
int minAns = INT_MAX, maxAns = INT_MIN;

vector<char> operUsed;

int cal(char op, int a, int b) {
	switch (op) {
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '%': return a / b; // 나눗셈은 몫만 리턴
	}
}

void dfs(int depth) {
	if (depth >= N-1) { // N 아니고 N-1
		int tmp = num[0];
		for (int i = 0; i < N - 1; ++i) {
			tmp = cal((char)operUsed[i], tmp, num[i + 1]);
		}
		minAns = min(tmp, minAns);
		maxAns = max(tmp, maxAns);
		return;
	}

	for (int i = 0; i< oper.size(); ++i) {
		if (operCnt[i] == 0) continue;
		operCnt[i]--;
		operUsed.push_back(oper[i]);
		dfs(depth + 1);
		operCnt[i]++;
		operUsed.pop_back();
	}

}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) cin >> num[i];
	for (int i = 0; i < 4; ++i) cin >> operCnt[i];

	dfs(0);
	cout << maxAns << "\n" << minAns;

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k;
char oper[10];

string ansMin = "9999999999";
string ansMax = "0000000000";

bool visited[10];
int ans[10];

void backTracking(int depth, string result) {
	if (depth > k) { // 범위 주의
		ansMax = max(result, ansMax);
		ansMin = min(result, ansMin);
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (visited[i]) continue;

		if (oper[depth - 1] == '>' && ans[depth - 1] < i) continue;
		if (oper[depth - 1] == '<' && ans[depth - 1] > i) continue;

		visited[i] = true;
		ans[depth] = i;
		result += i + '0';
		backTracking(depth + 1, result);
		visited[i] = false;
		result.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
		
	cin >> k;
	for (int i = 0; i < k; ++i) cin >> oper[i];
	
	backTracking(0,"");

	cout << ansMax << "\n" << ansMin;

	return 0;
}
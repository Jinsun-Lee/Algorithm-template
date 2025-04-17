#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

int K;       // K개 수(7 ~ 12 개)를 골라 집합을 만들어
int num[14]; // 집합 S
int ans[6];  // 1~49에서 6개

void backTrack(int depth, int start) {
	if (depth >= 6) { // K보다 클 때가 아니라 무조건 6개
		for (int i = 0; i < 6; i++) cout << ans[i] << " ";
		cout << endl;
		return;
	}

	for (int i = start; i < K; i++) { // K는 포함하지 않아야 해
		ans[depth] = num[i];
		backTrack(depth + 1, i + 1);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	while (1) {
		cin >> K;
		if (K == 0) break;
		else {

			// 입력 받아
			for (int i = 0; i < K; i++) cin >> num[i];
			backTrack(0, 0);

			cout << endl; // 케이스 사이에 빈줄
		}
	}

	return 0;
}
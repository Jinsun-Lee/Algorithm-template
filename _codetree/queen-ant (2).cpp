#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int x;     // 집 좌표
	bool del;  // 철거 여부
};

vector<Node> ants; // 모든 개미집

void f100() { // 초기 건설
	int n; cin >> n;
	ants.resize(n + 1); //★1번부터 시작

	ants[0].del = true; //★

	for (int i = 1; i <= n; ++i) {
		cin >> ants[i].x;
		ants[i].del = false;
	}
}

void f200() { // 추가 건설
	int p; cin >> p;
	ants.push_back({ p, false });
}

void f300() { // 철거
	int q; cin >> q;
	ants[q].del = true;
}

void f400() { // 최소 시간 출력
	int r; cin >> r; // r마리의 일개미

	int st = 0, en = 0x3f3f3f3f, ans = 0; //★

	while (st <= en) {
		int mid = (st + en) / 2;

		int cnt = 0; // 개미 하나가 커버할 수 없는 거리의 수
		int prev = -0x3f3f3f3f; // 이전 개미집의 좌표 //★

		for (auto& cur : ants) {
			if (cur.del) continue; // 300으로 철거된 것

			if (cur.x - prev > mid) { // 현재 개미집과 이전 개미집과의 거리가 mid보다 크면 새로운 구간을 추가
				prev = cur.x;
				++cnt;
			}
		}

		if (cnt <= r) {
			ans = mid;
			en = mid - 1;
		}
		else st = mid + 1;
	}
	cout << ans << "\n";
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	ios::sync_with_stdio(0); cin.tie(0);

	int Q; cin >> Q;
	while (Q--) {
		int oper; cin >> oper;
		if (oper == 100) f100();
		else if (oper == 200) f200();
		else if (oper == 300) f300();
		else if (oper == 400) f400();
	}
	return 0;
}

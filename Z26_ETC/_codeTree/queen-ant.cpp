#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> del(1); // 철거 여부
vector<int> pos(1); // 개미집 좌표

void f100() { // 마을 건설
	int N; cin >> N; // 초기에 마을이 몇 개인지
	
	int x; // 좌표값 임시
	for (int idx = 1; idx <= N; ++idx) {
		cin >> x;
		pos.push_back(x);
		del.push_back(0); // false
	}
}

void f200() { // 추가 건설
	int p; cin >> p;
	pos.push_back(p);
	del.push_back(0);
}

void f300() { // 철거
	int q; cin >> q; 
	del[q] = true;
}

void f400() { // 출력까지
	int r; cin >> r; // r마리의 일개미

	int st = 0;
	int en  = 1000000000; // 최대 시간
	
	int ans = 0; 

	while (st <= en) { // 이진탐색
		int mid = (st + en) / 2;

		int cnt = 0; // 개미 하나가 커버할 수 없는 거리의 수
		int prePos = -1000000000; // 이전 개미집의 좌표

		for (int i = 1; i < pos.size(); i++) {
			if (del[i]) continue; // 300으로 철거

			int curPos = pos[i]; // 현재 개미집의 위치
			
			// 현재 개미집과 이전 개미집과의 거리가 mid보다 크면 새로운 구간을 추가
			if (curPos - prePos > mid) {
				prePos = curPos;
				++cnt;
			}
		}

		if (cnt <= r) {
			ans = mid; 
			en  = mid - 1; 
		}
		else st = mid + 1; // mid-1만 뺴지 말고 여기도 

	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
  int Q; cin >> Q; // 명령의 수
	int oper; // 명령 번호
	while (Q--) { 
		cin >> oper; 
		if (oper == 100) f100();
		else if (oper == 200) f200();
		else if (oper == 300) f300();
		else if (oper == 400) f400();
	}
	return 0;
}

#include <iostream>
#include <vector>
using namespace std;

struct Node { 
    int x;    // 집 좌표
    bool del; // 철거 여부
};

vector<Node> ants; // 모든 개미집

void f100() { // 초기 건설
    //ants.clear();
    
    int N; cin >> N;
    ants.resize(N + 1); //★reserve랑 resize 차이 숙지
    ants[0].del = true; //★여왕개미의 집

    for (int i = 1; i <= N; ++i) {
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

bool check(const int& mid, const int& r) {
    int cnt = 0; // 개미 하나가 커버할 수 없는 거리의 수
    int pre = -1e9; //★이전 집의 좌표, 범위 왜 -1이 안 돼 -> 최대범위의 음수여야 센티넬로 동작함

    for (const auto& ant : ants){
        if (ant.del) continue; // 300으로 철거된 것

        if (ant.x - pre > mid) {
            ++cnt; // 현재 개미집과 이전 개미집과의 거리가 mid보다 크면 새로운 구간을 추가
            pre = ant.x; //★이것도 갱신을 해 줘야지
        } 
        
    }
    
    if (cnt > r) return false;
    return true;
}

void f400() { // 최소 시간 출력
    int r; cin >> r; // r마리의 일개미

    int st = 0, en = 1e9, mid; //★범위도 10000개여서 이렇게 잡지 말고 집의 좌표 최대로 
    int ans = en;
    while (st <= en) {
        mid = (st + en) / 2; //st/2 + en/2 + (1&st&en);

        if (check(mid, r)) {
            ans = mid;
            en = mid - 1; // 우리가 찾는 최소 간격이 더 작아도 돼
        }
        else st = mid + 1; //★거리 mid로는 부족 = st를 늘려야 해 
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int Q; cin >> Q;
    int oper;
    while (Q--) {
        cin >> oper;
        switch (oper) {
            case 100: { f100(); break; }
            case 200: { f200(); break; }
            case 300: { f300(); break; }
            case 400: { f400(); break; }
        }
    }
    return 0;
}

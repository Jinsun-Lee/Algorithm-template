#include <iostream>
#include <algorithm>
using namespace std;
 
int N, L, rate[20], cal[20], maxAns;

void dfs(int depth, int rSum, int cSum) {
    if (cSum > L) return;
    maxAns = max(maxAns, rSum);
    if (depth >= N) return;
 
    // 현재 음식 포함/미포함
    dfs(depth + 1, rSum + rate[depth], cSum + cal[depth]);
    dfs(depth + 1, rSum, cSum);
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    int tCase; cin >> tCase;
    for (int t = 1; t <= tCase; ++t) {
        cin >> N >> L;
        for (int i = 0; i < N; ++i) {
            cin >> rate[i] >> cal[i];
        }
        maxAns = 0;
        dfs(0, 0, 0);
        cout << "#" << t << " " << maxAns << "\n";
    }
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

vector<int> p;

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

void uni(int u, int v) {
    u = find(u);
    v = find(v);
 
    if (v < u) swap(u, v); // 
    p[v] = u;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int G, P; cin >> G >> P;
    p.assign(G + 1, -1);

    int t, gi;
    for (t = 0; t <= P; ++t) {
        cin >> gi;

        gi = find(gi); //
        if (gi == 0) break;
        uni(gi, gi - 1);
    }
    cout << t;
    return 0;
}
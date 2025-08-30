// Bottom-Up Segment Tree
// 18616 244 1187
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

using ll = long long;
vector<ll> tree;
int idx; // 원본 배열 시작 인덱스

void update(int node, ll val) {
	node += idx; // 0-based leaf 위치
    tree[node] = val; // leaf에 값 저장
    
    while (node > 1) {
        node /= 2;
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

ll query(int st, int en) {
    ll ans = 0;
    
    st += idx;
    en += idx;

    while (st <= en) {
        if (st % 2 == 1) ans += tree[st++];
        if (en % 2 == 0) ans += tree[en--];
        st /= 2;
        en /= 2;
    }

    return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, k; cin >> n >> m >> k;
    
    idx = (int)ceil(log2(n));
    int treeSize = 1 << (idx + 1); // 트리 전체 크기
    idx = 1 << idx;                // leaf 시작 인덱스
    
	tree.resize(treeSize, 0); 
    
    ll val;
	for (int i = 0; i < n; ++i) {
        cin >> val;
        update(i, val); 
    } 

	m += k;
	while (m--) {
		ll a, b, c; cin >> a >> b >> c;

		if (a == 1) update(b - 1, c); 
		else cout << query(b - 1, c - 1) << "\n";
	}
	return 0;
}
// Top - Down Segment Tree
// 노드 = 새로운값, 먼저 내려간 다음에 값 바꾸고 올라가면서 합 다시 구함
// 33464 432 1451
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
vector<ll> tree;

void update_range(int node, int st, int en, int L, int R, ll val) {
	//push_down(node, st, en);
    if (R < st || en < L) return;
    
    if (st == en) { 
        tree[node] = val; 
        return;
    }

	int mid = st + (en - st) / 2;
	update_range(2 * node, st, mid, L, R, val);
	update_range(2 * node + 1, mid + 1, en, L, R, val);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

ll query_range(int node, int st, int en, int L, int R) {
	//push_down(node, st, en);
    if (R < st || en < L) return 0;
	if (L <= st && en <= R) return tree[node];

	int mid = st + (en - st) / 2;
	ll lsum = query_range(2 * node, st, mid, L, R);
	ll rsum = query_range(2 * node + 1, mid + 1, en, L, R);
	return lsum + rsum;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, k; cin >> n >> m >> k;

	//arr.resize(n); 
	tree.resize(n * 4, 0); 
	//lazy.resize(n * 4, 0);
    
    ll value;
	for (int i = 1; i <= n; ++i){
        cin >> value;
        update_range(1, 0, n - 1, i-1, i-1, value); 
    }

	//init(1, 0, n - 1);

	m += k;
	while (m--) {
		ll a, b, c; cin >> a >> b >> c;

		if (a == 1) update_range(1, 0, n - 1, b - 1, b - 1, c); 
		else cout << query_range(1, 0, n - 1, b - 1, c - 1) << "\n";
	}
	return 0;
}
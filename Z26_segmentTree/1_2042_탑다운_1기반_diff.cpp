// Top - Down Segment Tree 
// 1기반 + diff 이용, 내려가면서 val만큼 증가
// 1부터 시작함 = 7개면 구간도 1 ~ 7
// 41280 280 1587
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
vector<ll> arr, tree;

void init(int node, int st, int en) {
	if (st == en) {
		tree[node] = arr[st];
		return;
	}

	int mid = st + (en - st) / 2;
	init(2 * node, st, mid); 
	init(2 * node + 1, mid + 1, en);
	tree[node] = tree[2 * node] + tree[2 * node + 1]; 
}

void update_range(int node, int st, int en, int L, int R, ll val) {
	//push_down(node, st, en);
    if (R < st || en < L) return;

	tree[node] += val; 

    if (st != en) { 
        int mid = st + (en - st) / 2;
	    update_range(2 * node, st, mid, L, R, val);
	    update_range(2 * node + 1, mid + 1, en, L, R, val);
    }
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

	arr.resize(n+1); 
	tree.resize(n * 4+1); 
	//lazy.resize(n * 4, 0);

	for (int i = 1; i <= n; ++i) cin >> arr[i];

	init(1, 1, n);

	m += k;
	while (m--) {
		ll a, b, c; cin >> a >> b >> c;

		if (a == 1) {
			ll diff = c - arr[b]; 
			arr[b] = c;          
			update_range(1, 1, n, b, b, diff); 
		}
		else cout << query_range(1, 1, n, b, c) << "\n";
	}
	return 0;
}
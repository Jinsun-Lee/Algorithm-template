// Top - Down Segment Tree with Lazy Propagation
// 72532 304 1984
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
vector<ll> tree, lazy;

void init(const vector<ll>& arr, int node, int st, int en) {
	if (st == en) {
		tree[node] = arr[st];
		return;
	}

	int mid = st + (en - st) / 2;
	init(arr, 2 * node, st, mid);
	init(arr, 2 * node + 1, mid + 1, en);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void push_down(int node, int st, int en) {
	if (lazy[node] == 0) return;

	tree[node] += (en - st + 1)*lazy[node];

	if (st != en) {
		lazy[2 * node] += lazy[node];
		lazy[2 * node + 1] += lazy[node];
	}

	lazy[node] = 0;
}

void update_range(int node, int st, int en, int L, int R, long long val) {
	push_down(node, st, en);

	if (R < st || en < L) return;

	if (L <= st && en <= R) {
		tree[node] += (en - st + 1) * val;

		if (st != en) {
			lazy[2 * node] += val;
			lazy[2 * node + 1] += val;
		}
		return;
	}

	int mid = st + (en - st) / 2;
	update_range(2 * node, st, mid, L, R, val);
	update_range(2 * node + 1, mid + 1, en, L, R, val);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

ll query_range(int node, int st, int en, int L, int R) {
	push_down(node, st, en);
    
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

	vector<ll> arr(n);
	tree.resize(n * 4, 0);
	lazy.resize(n * 4, 0);

	for (int i = 0; i < n; ++i) cin >> arr[i];

	init(arr, 1, 0, n - 1);

	m += k;
	int a; ll b, c;
	while (m--) {
		cin >> a;

		if (a == 1) {
			cin >> b >> c;
            ll diff = c - arr[b-1]; 
			arr[b-1] = c;     
			update_range(1, 0, n - 1, b - 1, b - 1, diff);
		}
		else {
			cin >> b >> c;
			cout << query_range(1, 0, n - 1, b - 1, c - 1) << "\n";
		}
	}
	return 0;
}
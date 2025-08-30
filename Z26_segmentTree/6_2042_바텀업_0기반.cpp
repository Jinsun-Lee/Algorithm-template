// Bottom-Up Segment Tree
// 26432 384 1607
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

using ll = long long;
vector<ll> arr, tree;
int idx; // 원본 배열 시작 인덱스

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
    
    idx = (int)ceil(log2(n));
    int treeSize = 1 << (idx + 1); // 트리 전체 크기
    idx = 1 << idx;                // leaf 시작 인덱스
    
	arr.resize(n); 
	tree.resize(treeSize, 0); 
	//lazy.resize(n * 4+1, 0);
    
    ll val;
	for (int i = 0; i < n; ++i) {
        cin >> val;
        arr[i]=val;
        update_range(1, 0, n - 1, i, i, val); 
    } 

	//init(1, 0, n - 1);

	m += k;
	while (m--) {
		ll a, b, c; cin >> a >> b >> c;

		if (a == 1) {
			ll diff = c - arr[b - 1]; 
			arr[b - 1] = c;          
			update_range(1, 0, n - 1, b - 1, b - 1, diff); 
		}
		else cout << query_range(1, 0, n - 1, b - 1, c - 1) << "\n";
	}
	return 0;
}
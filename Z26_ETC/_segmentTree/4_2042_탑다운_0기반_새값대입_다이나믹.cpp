// Dynamic Segment Tree
// tree의 크기를 넉넉하게 잡지 말고, 필요한 만큼만 잡게
// Top - Down Segment Tree & 노드에 바로 새로운값
// 33492 480 1882
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

struct NODE {
    ll value = 0;
    int left = 0;
    int right = 0;
};

NODE tree[1'001'000 * 2];
int tcnt = 2;

void update_range(int node, int st, int en, int L, int R, ll val) {
	//push_down(node, st, en);
    if (R < st || en < L) return;
    
    if (st == en) { 
        tree[node].value = val; 
        return;
    }
    
    if (tree[node].left == 0) tree[node].left = tcnt++;
    if (tree[node].right == 0) tree[node].right = tcnt++;
    
	int mid = st + (en - st) / 2;
    int leftNodeIndex = tree[node].left;
    int rightNodeIndex = tree[node].right;
    
	update_range(leftNodeIndex, st, mid, L, R, val);
	update_range(rightNodeIndex, mid + 1, en, L, R, val);
	tree[node].value = tree[leftNodeIndex].value + tree[rightNodeIndex].value;
}

ll query_range(int node, int st, int en, int L, int R) {
    if (node == 0) return 0;
    
	//push_down(node, st, en);
    if (R < st || en < L) return 0;
	if (L <= st && en <= R) return tree[node].value;

	int mid = st + (en - st) / 2;
	ll lsum = query_range(tree[node].left, st, mid, L, R);
	ll rsum = query_range(tree[node].right, mid + 1, en, L, R);
	return lsum + rsum;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, k; cin >> n >> m >> k;

	//arr.resize(n); 
	//tree.resize(n * 4, 0); 
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
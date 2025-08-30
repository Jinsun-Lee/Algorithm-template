// Dynamic Segment Tree
// tree의 크기를 넉넉하게 잡지 말고, 필요한 만큼만 잡게
// Top - Down Segment Tree & 노드에 바로 새로운값 & 포인터 링크드 리스트
// 49132 480 1887
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

struct NODE {
    ll value;
    NODE* left;
    NODE* right;
};

NODE ROOT;
NODE tree[1'001'000 * 2];
int tcnt;

void update_range(NODE* node, int st, int en, int L, int R, ll val) {
	//push_down(node, st, en);
    if (R < st || en < L) return;
    
    if (st == en) { 
        node->value = val; 
        return;
    }
    
    if (node->left == NULL) {
        node->left = &tree[tcnt++];
        node->right = &tree[tcnt++];
    } 
    
	int mid = st + (en - st) / 2;
    NODE* leftNodeIndex = node->left;
    NODE* rightNodeIndex = node->right;
    
	update_range(leftNodeIndex, st, mid, L, R, val);
	update_range(rightNodeIndex, mid + 1, en, L, R, val);
	node->value = leftNodeIndex->value + rightNodeIndex->value;
}

ll query_range(NODE* node, int st, int en, int L, int R) {
    if (node == NULL) return 0;
    
	//push_down(node, st, en);
    if (R < st || en < L) return 0;
	if (L <= st && en <= R) return node->value;

	int mid = st + (en - st) / 2;
	ll lsum = query_range(node->left, st, mid, L, R);
	ll rsum = query_range(node->right, mid + 1, en, L, R);
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
        update_range(&ROOT, 0, n - 1, i-1, i-1, value); 
    }

	//init(1, 0, n - 1);

	m += k;
	while (m--) {
		ll a, b, c; cin >> a >> b >> c;

		if (a == 1) update_range(&ROOT, 0, n - 1, b - 1, b - 1, c); 
		else cout << query_range(&ROOT, 0, n - 1, b - 1, c - 1) << "\n";
	}
	return 0;
}
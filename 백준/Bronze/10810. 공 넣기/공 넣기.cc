#include <iostream>
#include <algorithm>
using namespace std;

int N[101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m, i, j, k; 
    cin >> n >> m;
    while (m--) {
        cin >> i >> j >> k;
        fill(&N[i], &N[j+1], k);
    }

    for (int i = 1; i <= n; ++i) cout << N[i] << " ";
    return 0;
}
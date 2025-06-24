#include <iostream>
#include <algorithm>
using namespace std;

int N[101], tmp[101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    int n, m, i, j, k;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) N[i] = i;

    while (m--) {
        cin >> i >> j >> k;

        int diff = i + j - k;
        for (int t=i; t<=j; ++t) {
            if (t < k) tmp[t+ diff-i+1]=N[t];
            else N[t+diff-j]=N[t];
        }
        for (int t = diff+1; t <= j; ++t) N[t] = tmp[t];
    }

    for (int i = 1; i <= n; ++i) cout << N[i] << " ";
    return 0;
}
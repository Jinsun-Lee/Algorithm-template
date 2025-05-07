#include <iostream>
#include <algorithm>
using namespace std;

int N, K, psum[102], maxAns = -102;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> K;
    for (int i = 1; i <= N; ++i) {
        cin >> psum[i];
        psum[i] += psum[i - 1];
    }

    for (int L = 0, R = K; R <= N; L++, R++) {
        maxAns = max(maxAns, psum[R] - psum[L]);
    }

    cout << maxAns;
    return 0;
}
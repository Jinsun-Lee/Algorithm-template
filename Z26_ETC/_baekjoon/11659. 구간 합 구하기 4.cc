#include <iostream>
using namespace std;

int psum[100'001];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, tc; cin >> n >> tc;
  for (int i = 1; i <= n; ++i) {
    cin >> psum[i];
    psum[i] += psum[i - 1];
  }

  int a, b;
  while (tc--) {
      cin >> a >> b;
      cout << psum[b] - psum[a - 1] << "\n"; 
  }
  return 0;
}

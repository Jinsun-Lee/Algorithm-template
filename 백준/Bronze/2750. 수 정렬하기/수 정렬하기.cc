#include <bits/stdc++.h>
using namespace std;

const int MXN = 2000, HALF = MXN / 2;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<bool> arr(MXN + 2);
  int N, t;
  cin >> N;
  while (N--) {
    cin >> t;
    arr[t + HALF] = true;
  }
  for (int i = 0; i <= MXN; i++)
    if (arr[i]) cout << i - HALF << '\n';
}
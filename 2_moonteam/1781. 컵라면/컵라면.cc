#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);

  int N, dl, cn;
  unsigned int cupNoodles = 0;
  priority_queue<unsigned int> cn_candidate;
  vector<vector<unsigned int>> cn_by_deadline(200'002);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> dl >> cn;
    cn_by_deadline[dl].push_back(cn);
  }
  for (int curr = 200'001; curr != 0; curr--) {
    for (int noodle : cn_by_deadline[curr])
      cn_candidate.push(noodle);

    if (cn_candidate.empty()) continue;
    cupNoodles += cn_candidate.top();
    cn_candidate.pop();
  }
  cout << cupNoodles;
}
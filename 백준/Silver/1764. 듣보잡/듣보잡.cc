#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int N, M; cin >> N >> M; // 듣지못한 사람, 보지 못한 사람 수
	
	string tmp;
	set<string> list;
	vector<string> ans;

	while (N--) {
		cin >> tmp;
		list.insert(tmp);
	}

	while (M--) {
		cin >> tmp;
		if (list.find(tmp) != list.end()) ans.push_back(tmp);
	}

	cout << ans.size() << "\n";
    sort(ans.begin(), ans.end()); // 사전순 정렬
	for (const string& name : ans) cout << name << "\n";

	return 0;
}
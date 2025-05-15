#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int N, M; cin >> N >> M;

	string tmp;
	set<string> S;
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		S.insert(tmp);
	}

	int cnt = 0;
	for (int i = 0; i < M; ++i) {
		cin >> tmp;
		if (S.find(tmp) != S.end()) cnt++;
	}
	cout << cnt;
	return 0;
}
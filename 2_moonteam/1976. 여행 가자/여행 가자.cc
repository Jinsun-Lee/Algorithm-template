#include <iostream>

using namespace std;

int n, m; // 도시의수, 계획한도시의수

int Group[201]; //

int Find(int &now) {
	if (Group[now] == now) return now;
	return Group[now] = Find(Group[now]);
}

void Union(int &a, int &b) {
	int pA = Find(a);
	int pB = Find(b);

	if (pA == pB) return;

	Group[pB] = pA;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		Group[i] = i;
	}

	int t;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> t;
			
			if (t == 1) {
				Union(i, j);
			}
		}
	}

	int grp;
	cin >> t;
	grp = Find(t);
	for (int i = 2; i <= m; i++) { // n이 아닌 m
	//while(cin >> t){
		cin >> t;
		if (Find(t) != grp) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}
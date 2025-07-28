#include <iostream>

using namespace std;

int n, m;

int* Group; //

int Find(int now) {
	if (Group[now] == now) return now;
	return Group[now] = Find(Group[now]);
}

void Union(int a, int b) {
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

	Group = new int[n + 1] {0}; // 

	for (int i = 1; i <= n; i++) {
		Group[i] = i;
	}

	int t, a, b;

	while(m--) {
		cin >> t >> a >> b;
		
		if (t == 0) {
			// 합집합, a가 포함된 집합, b가 포함된 집합
			Union(a, b);
		}

		else {
			// 두 원소가 같은 집합에 포함되어 있는지 확인하는 연산
			if (Find(a) == Find(b)) cout << "yes" << "\n";
			else cout << "no" << "\n";
		}

	}

	return 0;
}
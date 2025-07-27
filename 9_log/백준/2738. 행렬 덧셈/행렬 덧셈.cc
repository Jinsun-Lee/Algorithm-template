#include <iostream>
using namespace std;

const int MX = 101;
int a[MX][MX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tmp;
			a[i][j]+=tmp;
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int t[20]; // 통화 개수
int Y, M;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) cin >> t[i];
	
	for (int i = 0; i < n; i++) Y += ((t[i] / 30) + 1) * 10;
	for (int i = 0; i < n; i++) M += ((t[i] / 60) + 1) * 15;

	if (Y > M) cout << "M " << M;
	else if (Y < M) cout << "Y " << Y;
	else cout << "Y M " << Y;

	return 0;
}
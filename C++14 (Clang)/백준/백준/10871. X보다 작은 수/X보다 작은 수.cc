#include <iostream>

using namespace std;

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, X, tmp;
	cin >> N >> X;

	while(N--){
		cin >> tmp;
		if (tmp < X) cout << tmp << " ";
	}

	return 0;
}
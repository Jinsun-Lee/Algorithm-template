#include <iostream>
using namespace std;

void cal(int w, int h, int p, int q, int t) {
	// 시간에 따른 개미의 위치 계산
	int np = (p + t) % (2 * w);
	int nq = (q + t) % (2 * h);

	if (np > w) np = 2 * w - np;
	if (nq > h) nq = 2 * h - nq;

	cout << np << " " << nq;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int w, h, p, q, t;
	cin >> w >> h >> p >> q >> t;

	cal(w, h, p, q, t);
	return 0;
}
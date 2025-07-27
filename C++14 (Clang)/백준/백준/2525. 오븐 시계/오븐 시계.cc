#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
		
	int h, m, c;
	cin >> h >> m >> c;

	h += c / 60;
	m += c % 60;

	if (m >= 60) {
		h++;
		m-=60;
	}
	
	if (h >= 24) h-=24; // h=0으로 만들면 안 돼

	cout << h << " " << m;

	return 0;
}
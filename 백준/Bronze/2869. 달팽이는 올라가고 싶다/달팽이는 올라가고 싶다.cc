#include <iostream>
#include <cmath>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int A, B, V; cin >> A >> B >> V;
    
    // 100 99 1000000000 넣었을 때 1e+09로 나오네
	cout << (long long)ceil((double)(V - B) / (A - B));
	return 0;
}
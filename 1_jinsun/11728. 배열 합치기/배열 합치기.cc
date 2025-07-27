#include <iostream>
using namespace std;
#define FASTIO cin.tie(0)->sync_with_stdio(0)

int A[1000000], B[1000000], C[2000000];

int main() {
	FASTIO;

	int a, b; cin >> a >> b;
	for (int i = 0; i < a; ++i) cin >> A[i];
	for (int i = 0; i < b; ++i) cin >> B[i];

	int ia = 0, ib = 0;
	for (int i = 0; i < a + b; ++i) {
		if (ia == a) C[i] = B[ib++]; 
		else if (ib == b) C[i] = A[ia++];
		else if (A[ia] <= B[ib]) C[i] = A[ia++]; 
		else C[i] = B[ib++];
	}

	for (int i = 0; i < a + b; ++i) cout << C[i] << " ";
	return 0;
}
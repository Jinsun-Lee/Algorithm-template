#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;
#define FASTIO cin.tie(0)->sync_with_stdio(0)

int N;

bool cmp(const string& a, const string& b) {
	int lenA = a.size(), lenB = b.size();
	if (lenA != lenB) return lenA < lenB;

	int sumA = 0, sumB = 0;
	for (int i = 0; i < lenA; ++i) {
		if (isdigit(a[i])) sumA += (a[i] - '0'); 
		if (isdigit(b[i])) sumB += (b[i] - '0');
	}
	if (sumA != sumB) return sumA < sumB;

	return a < b; 
}

int main() {
	FASTIO;
	
	cin >> N; 
	vector<string> v(N);
	for (int i = 0; i < N; ++i) cin >> v[i];

	sort(v.begin(), v.end(), cmp);

	for(auto i : v) cout << i << '\n';
	return 0;
}
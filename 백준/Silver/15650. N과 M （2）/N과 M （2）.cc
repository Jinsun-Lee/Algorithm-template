#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
vector<int> vec;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	
	// M의 개수만큼 0을 넣어줌
	for(int i = 0; i < N; i++) vec.push_back(i < M ? 0 : 1);

	do {
		for(int i = 0; i < N; i++){
			if(vec[i]==0) cout << i+1 << " ";
		}
		cout << "\n";
	} while(next_permutation(vec.begin(),vec.end()));

	return 0;
}
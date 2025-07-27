#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen_s(new FILE*,"input.txt","r",stdin);
	
	int n;
	bool count[42] = {};

	for(int i = 0; i < 10; i++){
		cin >> n;

		count[n%42]=true;
	}
	
	int result = 0;
	for(auto i : count){
		if(i) result++;
	}

	cout << result;

	return 0;
}
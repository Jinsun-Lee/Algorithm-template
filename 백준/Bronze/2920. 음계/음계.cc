#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen_s(new FILE*,"input.txt","r",stdin);
	
	int arr[8];
	for(int i = 0; i < 8; i++) {
		cin >> arr[i];
	}

	bool ascending = true,descending = true;

	for(int i = 0; i < 7; i++) {
		if(arr[i] > arr[i + 1]) ascending = false;
		if(arr[i] < arr[i + 1]) descending = false;
	}

	if(ascending) cout << "ascending";
	else if(descending) cout << "descending";
	else cout << "mixed";

	return 0;
}
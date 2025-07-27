#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen_s(new FILE*,"input.txt","r",stdin);
	
	int tCase; cin >> tCase;

	while(tCase--){

		string str;
		cin >> str;

		int index=0, sum=0;
		for(int i = 0; i < str.length(); i++){
			if(str[i]=='X') {
				index = 0;
			}
			else {
				index++;
				sum+=index;
			}
			//cout << index << " ";
		}
		cout << sum << "\n";
	}

	return 0;
}
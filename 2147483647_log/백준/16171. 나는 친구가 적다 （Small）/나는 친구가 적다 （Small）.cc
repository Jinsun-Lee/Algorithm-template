#include <iostream>
#include <string>
using namespace std;
int main(){
	//freopen_s(new FILE*,"input.txt","r",stdin);
	string s,target;
	cin >> s >> target;

	string ans="";
	for(int i = 0; i < s.length(); i++){
		if(s[i]-'0'>=0 && s[i]-'0'<=9) continue;
		ans+=s[i];
	}

	int index = 0;
	index = ans.find(target,index);
	if(index==-1) cout << 0;
	else cout << 1;

	return 0;
}
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen_s(new FILE*,"input.txt","r",stdin);

	while(true){
		//!cin.eof()){ // 끝에 올 때까지 반복 =cin.eof()==1
		//cin.getline(str,'.');
		//char str[100];

		string a;
		getline(cin, a);
		if(a == ".") break;

		stack<char> s;
		bool isValid = true;

		for(auto c : a){
			if(c == '(' || c == '[') s.push(c);

			else if(c == ')'){
				if(s.empty() || s.top() != '('){
					isValid = false;
					break;
				}
				s.pop();
			}

			else if(c == ']'){
				if(s.empty() || s.top() != '['){
					isValid = false;
					break;
				}
				s.pop();
			}
		}

		if(!s.empty()) isValid = false;
		if(isValid) cout << "yes\n";
		else cout << "no\n";

	}
	
	return 0;
}
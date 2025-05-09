#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int N; cin >> N;
	for (int i = 1; i <= N; ++i) {

		bool has369 = false;
		string num = to_string(i); // num = i + '0'; 아냐
		
		for (int j = 0; j < num.length(); ++j) {
			if (num[j] == '3' || num[j] == '6' || num[j] == '9') { // '숫자'
				has369 = 1;
				cout << "-";
			}
		}
		if (has369 == false) cout << i; // else로 i 출력하지 말고 이렇게 해
		cout << " ";
	}
	return 0;
}
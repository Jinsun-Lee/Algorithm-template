#include <iostream>
#include <string> // getline
#include <iomanip> // setprecision
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	map<string, int> trees;
	string name;
	double size = 0;

	while (getline(cin, name)) {
		trees[name]++;
		size++;
	}

	cout << fixed << setprecision(4); // 소수점 4째자리
	for (auto& tree : trees) {
		cout << tree.first << " " << (tree.second / size)*100 << "\n";
	}
	
	return 0;
}
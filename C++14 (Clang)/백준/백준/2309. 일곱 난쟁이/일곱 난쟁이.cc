#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int a[9];
int dep = 7;
bool visited[9] = { 0 }; //
bool found = false; //

void dfs(int depth, vector<int> &vec) { //
	if (found) return; //

	if (depth >= dep) { //
		int sum = 0;
		for (int i : vec) { //
			sum += i;
		}
		if (sum == 100) {
			sort(vec.begin(), vec.end()); // 악 좀... 놓치지 마...
			for (int i : vec) {
				cout << i << "\n";
				found = true; //
			}
		}
		return;
	}

	for (int i = 0; i < 9;i++) { //		
		if (visited[i]) continue; //

		vec.push_back(a[i]); //
		visited[i] = 1; //
		dfs(depth + 1, vec); //
		vec.pop_back();
		visited[i] = 0; 
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	for (int i = 0; i < 9; i++) cin >> a[i];

	vector<int> vec; //
	dfs(0, vec);

	return 0;
}
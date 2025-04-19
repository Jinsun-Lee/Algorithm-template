#include <iostream>
using namespace std;

// 여러 테스트
void init() {
    for (int i = 0; i < MX; i++) {
        v[i].clear();
        visited[i] = 0;
    }
    mxSheep = 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

    // 5
    cout << solution({ 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1 },
        { {0, 1}, {1, 2}, {1, 4}, {0, 8}, {8, 7}, {9, 10}, {9, 11}, {4, 3}, {6, 5}, {4, 6}, {8, 9} }
    ) << endl;

    init();

    // 5
    cout << solution({ 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0 },
        { {0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {3, 7}, {4, 8}, {6, 9}, {9, 10} }
    ) << endl; 

	return 0;
}
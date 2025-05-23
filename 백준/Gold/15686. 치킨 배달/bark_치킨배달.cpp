#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

struct Node { int y, x; };
vector<Node> home, chicken;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen_s(new FILE*, "input.txt", "r", stdin);

    int N, M, tmp; cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> tmp;
            if (tmp == 1) home.push_back({ i, j });
            else if (tmp == 2) chicken.push_back({ i, j });
        }
    }

    int ans = INT_MAX;

    vector<int> select(chicken.size(), 1); //⭐치킨집이 5, M=3이면 00011
    fill(select.begin(), select.begin() + chicken.size() - M, 0); 

    do {
        int sum = 0;
        for (const auto& h : home) {
            int dist = 2 * N;
            for (size_t i = 0; i < chicken.size(); i++) {
                if (select[i] == 0) continue; 
                dist = min(dist, abs(h.y - chicken[i].y) + abs(h.x - chicken[i].x));
            }
            sum += dist;
        }
        ans = min(ans, sum);
    } while (next_permutation(select.begin(), select.end()));

    cout << ans;
    return 0;
}
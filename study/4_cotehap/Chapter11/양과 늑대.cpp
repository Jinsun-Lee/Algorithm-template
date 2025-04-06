#include <iostream>
#include <vector>  
using namespace std;

const int MX = 18;
vector<int> v[MX];
int visited[MX], sheep, wolf, mxSheep;

void dfs(vector<int> cur, vector<int> info) { //
    sheep = 0, wolf = 0; 

    for (int i = 0; i < cur.size(); i++) { //
        if (info[cur[i]] == 1) wolf++; //
        else sheep++;
    }

    if (sheep <= wolf) return;

    if (mxSheep < sheep) mxSheep = sheep; // 

    for (int i = 0; i < cur.size(); i++) { //
        int nxt = cur[i]; // 

        // 현재 노드와 인접한 노드를 순회
        for (int j = 0; j < v[nxt].size(); j++) {
            
            if (visited[v[nxt][j]]) continue;

            visited[v[nxt][j]] = 1;
            cur.push_back(v[nxt][j]); // 
            dfs(cur, info);
            visited[v[nxt][j]] = 0;
            cur.pop_back();
        }
    }

}

int solution(vector<int> info, vector<vector<int>> edges) {

    // 연결
    for (int i = 0; i < info.size()-1 ; i++) { // 주의
        v[edges[i][0]].push_back(edges[i][1]); // 
    }

    dfs({ 0 }, info); // 

    return mxSheep;
}

// 여러 테스트
void init() {
    for (int i = 0; i < MX; i++) {
        v[i].clear();
        visited[i] = 0;
    }
    mxSheep = 0;
}

int main() {
	//ios::sync_with_stdio(0); cin.tie(0);

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
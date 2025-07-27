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
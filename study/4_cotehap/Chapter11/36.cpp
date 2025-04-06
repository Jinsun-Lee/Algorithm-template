#include <iostream>
#include <vector>
#include <unordered_map> // 사전순으로 탐색할 때 편하게
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <iterator>
using namespace std;

unordered_map<char, vector<char>> adjList;
unordered_set<char> visited;

vector<char> result;

void dfs(char start) {
    stack<char> st;
    st.push(start);

    while (!st.empty()) {
        char cur = st.top();
        st.pop();

        // 방문한 적 없다면 방문 처리
        //if (visited.count(cur)) continue;
        if (visited.find(cur) == visited.end()) {
            visited.insert(cur);
            result.push_back(cur);

            // 사전 순으로 DFS를 보장하기 위해 역순으로
            vector<char>& neighbors = adjList[cur];
            sort(neighbors.rbegin(), neighbors.rend());

            // 현재 노드와 인접한 노드 중, 방문하지 않은 곳 탐색
            for (char neighbor : adjList[cur]) {
                if (visited.find(neighbor) == visited.end()) {
                    st.push(neighbor);
                }
            }
        } // if문 끝

    }
}

vector<char> solution(vector<pair<char, char>> graph, char start) {
    // 입력 처리
    for (int i = 0; i < graph.size(); i++){
        char u = graph[i].first;
        char v = graph[i].second;
        adjList[u].push_back(v);
    }

    dfs(start);
    return result;
}

void print(vector<char> vec) {
    copy(vec.begin(), vec.end(), ostream_iterator<char>(cout, " "));
    cout << "\n";
}

void init() {
    adjList.clear();
    visited.clear();
    result.clear();
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    // 출력값 : A B C D E
    print(solution({ {'A', 'B'}, {'B', 'C'}, {'C', 'D'}, {'D', 'E'} }, 'A'));

    init();

    //출력값 : A B D E F C
    print(solution({ {'A', 'B'}, {'A', 'C'}, {'B', 'D'}, {'B', 'E'}, {'C', 'F'}, {'E', 'F'} }, 'A'));

    return 0;
}
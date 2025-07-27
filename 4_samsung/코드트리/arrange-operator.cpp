#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int N;
int num[12], operCnt[3];
string oper = "+-*";
int maxAns=INT_MIN, minAns=INT_MAX;
vector<char> result;

int cal(char op, int a, int b){
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
    }
}

void dfs(int depth){
    if (depth>=N-1){
        int tmp = num[0];
        for (int i = 0; i < N-1; ++i){
            tmp = cal((char)result[i], tmp, num[i+1]);
        }
        maxAns = max(tmp, maxAns);
        minAns = min(tmp, minAns);
        return;
    }

    for (int i = 0; i < oper.size(); ++i){ // 연산이 3개니까
        if (operCnt[i]==0) continue;

        operCnt[i]--;
        result.push_back(oper[i]);
        dfs(depth+1);
        result.pop_back();
        operCnt[i]++;
    }

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) cin >> num[i];  
    for (int i = 0; i < 3; ++i) cin >> operCnt[i];

    dfs(0);
    cout << minAns << " " << maxAns;

    return 0;
}
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
#define endl "\n"

int N;               // 일의 양, N이 4~20
int map[21][21];     // 각 값은 1~100
vector<int> day, night; 
vector<bool> used;
int minDiff = INT_MAX;

int getSum(const vector<int>& vec){
    int sum = 0;
    int len = vec.size();
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            sum += map[vec[i]][vec[j]]; //+map[vec[j]][vec[i]];
        }
    }
    return sum;
}

void dfs(int depth, int start) {

    if (depth == N / 2) {
        
        // 이전 값 제거
        day.clear(); 
        night.clear(); 

        // used 배열로 day와 night 팀을 나누기
        for (int i = 0; i < N; ++i) {
            if (used[i]) day.push_back(i);
            else night.push_back(i);
        }

        int sumD = getSum(day);
        int sumN = getSum(night);
        minDiff = min(minDiff, abs(sumD - sumN));

        return;
    }

    for (int i = start; i < N; ++i) {
        used[i]=true;
        dfs(depth + 1, i + 1);
        used[i] = false;
    }

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    //freopen_s(new FILE*, "input.txt", "r", stdin); // 5, 19

    // 1. 입력 처리, 누적합 사용
    cin >> N;
    
    int tmp;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> tmp;
            if (i < j) map[i][j] = tmp;
            else {
                map[i][j] = 0;
                map[j][i] += tmp;
            }
        }
    }
    
    // 2. N/2로 조합 생성
    used.assign(N, false);
    dfs(0, 0);

    // 3. 조합 별로 강도 구하고, 최소값 저장
    cout << minDiff << endl;

    return 0;
}

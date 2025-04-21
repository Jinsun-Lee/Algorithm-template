#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
#define endl "\n"

/*
n개의 일, 각각 n/2씩 조합 생성하고(N은 2의 배수)
|아침(P12+P21) - 저녁(P34+P43)|가 최소가 되도록

<헷갈>
- 강도가 큰 건 상관없고, 차이만 최소가 되면 되려나?

<수정>
- 기준을 1부터로 잡을 필요가 없어, Pij=0만 주의
*/

/* <백트래킹 조건>

i==j는 넘겨도 돼


*/

int N; // 일의 양, N이 4~20
int map[21][21]; // 각 값은 1~100
vector<int> day(11), night(11); // 낮밤 최대 10개씩으로 사이즈 제한
int sumD, sumN, minDiff;

int getSum(vector<int>& vec) {
    int sum = 0;
    int len = vec.size();
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            sum += map[vec[i]][vec[j]] + map[vec[j]][vec[i]];
        }
    }
    return sum;
}

void dfs(int depth, int start) {
    if (depth >= N / 2) {
        
        // day에 없는 숫자들을 night에 추가
        //for (int i = 0; i < N; ++i) {
        //    if (!day[i]) night.push_back(i+1);
        //}

        // night 초기화
        vector<bool> isDay(N, false);
        for (int i : day) isDay[i] = true;
        night.clear();
        for (int i = 0; i < N; ++i) {
            if (!isDay[i]) night.push_back(i);
        }

        // day랑 night 각자 n/2개의 숫자가 있고, 그 숫자들에서 2개씩 뽑아 계산
  
        /*
        //vector<bool> tmp(day.size(), true);
        //for (int i = 0; i < day.size() - 2; ++i) tmp[i] = false;
        int len = day.size(); vector<bool> tmp(len);
        fill(tmp.end() - 2, tmp.end(), true);
        do {
            for (int i = 0; day.size(); ++i) {
                if (tmp[i]) cout << day[i] << " ";
            }
            cout << endl;
        } while (next_permutation(tmp.begin(), tmp.end()));
        */

        sumD = getSum(day);
        sumN = getSum(night);
        minDiff = min(minDiff, abs(sumD - sumN));
        
        return;
    }
    
    for (int i = start; i < N; ++i) {
        day.push_back(i);
        dfs(depth + 1, i+1);
        day.pop_back();
    }
}

void init() {
    sumD = sumN = 0; 
    minDiff = INT_MAX;
    day.clear();
    night.clear();
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    //freopen_s(new FILE*, "input.txt", "r", stdin); // 5, 19

    init();

    // 1. 입력 처리
    cin >> N;
    for (int i = 0; i < N; ++i) { 
        for (int j = 0; j < N; ++j) {
            cin >> map[i][j];
        }
    }

    // 2. N/2로 조합 생성
    dfs(0, 0);

    // 3. 조합 별로 강도 구하고, 최소값 저장
    cout << minDiff << endl;

    return 0;
}

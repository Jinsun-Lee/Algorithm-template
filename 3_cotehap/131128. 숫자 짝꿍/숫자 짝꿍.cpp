#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    vector<int> xCnt (10, 0); // 10
    vector<int> yCnt (10, 0);
    vector<int> sameCnt (10, 0);
    
    for (char c : X) xCnt[c -'0']++; //
    for (char c : Y) yCnt[c -'0']++;
    
    for (int i = 0; i < 10; i++) {
        sameCnt[i] = min(xCnt[i], yCnt[i]); 
    }
    
    for (int i = 9; i >= 0; i--){
        if (sameCnt[i] > 0){
            // answer += string(sameCnt[i], '0'+sameCnt[i]);
            answer += string(sameCnt[i], '0'+i); // 숫자 i를 sameCnt[i]만큼 추가
        }
    }
    
    if(answer.empty()) return "-1"; // "000000" 말고
    if(answer[0]=='0') return "0"; // 0이라고 쓰거나 "0"라고 쓰면 안 돼 '0'
    return answer;
}
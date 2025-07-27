#include <iostream>
#include <algorithm>
using namespace std;
#define endl "\n"

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
   
    int tCase = 3, cnt, ans;
    string str;
    
    while (tCase--) {
        cin >> str;

        cnt = 1, ans = 1; // 연속은 최소 1개
        for (int i = 0; i < 7; ++i) {
            if (str[i] == str[i+1]) cnt++;
            else cnt = 1; // 한 번만 쓰면 돼

            ans = max(cnt, ans);
        }
        cout << ans << endl;
    }
    
    return 0;
}
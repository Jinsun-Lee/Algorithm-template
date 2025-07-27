#include <iostream>
#include <vector>
#include <limits.h>
 
using namespace std;
 
int n, m;
vector<pair<string, string>> vec;
vector<bool> visited;
 
int ans = INT_MAX;
int res = 0;
 
void recur(int cur, int cnt)
{
    if (cur == n)
    {
        vector<bool> song(m, false);
 
        // 부를 수 있는 노래 개수
        int _cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false) continue;
 
            string temp = vec[i].second;
            for (int j = 0; j < temp.length(); j++)
            {
                if (temp[j] == 'Y' && song[j] == false)
                {
                    song[j] = true;
                    _cnt++;
                }
            }
        }
 
        if (res < _cnt)
        {
            res = _cnt;
            ans = cnt;
        }
        else if (res == _cnt)
        {
            res = _cnt;
            ans = min(ans, cnt);
        }
 
        return;
    }
    
    visited[cur] = true;
    recur(cur + 1, cnt + 1);
    visited[cur] = false;
    recur(cur + 1, cnt);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    vec.resize(n);
    for (int i = 0; i < n; i++) cin >> vec[i].first >> vec[i].second;
 
    visited.resize(n, false);
 
    recur(0, 0);
 
    if (ans == 0) ans--;
    cout << ans;
 
    return 0;
}
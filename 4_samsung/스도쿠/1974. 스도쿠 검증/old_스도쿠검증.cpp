#include <iostream>
#include <tuple> // tie(y, x)
using namespace std;
 
bool has10(bool chk[9]) {
    for (int i = 0; i < 9; ++i) {
        if (!chk[i]) return false;
    }
    return true;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    int tc; cin >> tc;
    int map[9][9];
    pair<int, int> coord[] = {  {1,1}, {1,4}, {1,7},
                                {4,1}, {4,4}, {4,7},
                                {7,1}, {7,4}, {7,7}};
    int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
     
    for (int t = 1; t <= tc; ++t) {
        bool unique = true;
 
        // 입력
        for (int h = 0; h < 9; ++h) {
            for (int w = 0; w < 9; ++w) {
                cin >> map[h][w];
            }
        }
 
        // 가로 검사
        for (int h = 0; h < 9 && unique; ++h) { // && uique
            bool chk[9] = {}; // 이렇게 초기화
            for (int w = 0; w < 9; ++w) {        
                chk[map[h][w]-1] = 1; // 값이 1~9라서 인덱스로 접근하려면 -1
            }
            if(!has10(chk)) unique = false;
        }
 
        // 세로 검사
        for (int w = 0; w < 9 && unique; ++w) {
            bool chk[9] = {};
            for (int h = 0; h < 9; ++h) {
                chk[map[h][w] - 1] = 1;
            }
            if (!has10(chk)) unique = false;
        }
 
        // 대각선
        for (pair<int, int>& p : coord) {
            bool chk[9] = {};
            for (int i = 0; i < 8; ++i) {
                int ny = p.first + dy[i];
                int nx = p.second + dx[i];
                chk[map[ny][nx]-1] = 1;
            }
            chk[map[p.first][p.second] - 1] = 1; // 나 자신의 칸도 봐야지
            if (!has10(chk)) unique = false;
        }
 
        cout << "#" << t << " " << ((unique) ? 1 : 0) << "\n";
    }
    return 0;
}
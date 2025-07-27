#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[300][300];
bool check[300][300];
int cnt;
int meltCnt = 0;
vector<pair<int, int>> input;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool check_end(){
    for(int i = 0; i < input.size(); i++){
        int row = input[i].first;
        int col = input[i].second;
        if(arr[row][col]) return false;
    }
    return true;
}

bool check_divide(){
    int inputCnt = 0;
    queue<pair<int, int>> q;
    for(int i = 0; i < input.size(); i++){
        int row = input[i].first;
        int col = input[i].second;
        if(!arr[row][col]) continue;
        else{
            q.push({row, col});
            break;
        }
    }
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        inputCnt++;
        q.pop();
        check[row][col] = true;
        for(int j = 0; j < 4; j++){
            int nRow = row + dy[j];
            int nCol = col + dx[j];
            if(check[nRow][nCol] || nRow < 0 || nRow >= N || nCol < 0 || nCol >= M)
                continue;
            if(arr[nRow][nCol]){
                check[nRow][nCol] = true;
                q.push({nRow, nCol});
            }
        }
    }
    memset(check, 0, sizeof(check));
    if(inputCnt == input.size() - meltCnt) return false;
    return true;
}

void do_solution(){
    for(int i = 0; i < input.size(); i++){
        int row = input[i].first;
        int col = input[i].second;

        if(!arr[row][col]) continue;

        check[row][col] = true;
        int oceanCnt = 0;
        for(int j = 0; j < 4; j++){
            int nRow = row + dy[j];
            int nCol = col + dx[j];

            if(check[nRow][nCol] || nRow < 0 || nRow >= N || nCol < 0 || nCol >= M)
                continue;
            if(!arr[nRow][nCol])
                oceanCnt++;
        }
        if(arr[row][col] - oceanCnt <= 0){
            meltCnt++;
            arr[row][col] = 0;
        }
        else arr[row][col] -= oceanCnt;
    }
    memset(check, 0, sizeof(check));
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
            if(arr[i][j]) input.push_back({i, j});
        }
    }
    
    while(1){
        do_solution();
        cnt++; 
        if(check_divide()){
            cout << cnt << '\n';
            return 0;
        }
        if(check_end()){
            cout << 0 << '\n';
            return 0;
        }
    }
    return 0;
}
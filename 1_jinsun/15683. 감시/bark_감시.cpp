// 2212	20 2504
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;

int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

int board1[10][10]; // 입력으로 주어지는 초기 상태
int board2[10][10]; // cctv의 방향을 정한 후에 사각지대를 세기 위한 변수

vector<pair<int,int> > cctv; // cctv의 좌표를 저장할 변수

bool OOB(int a, int b){ // 영역을 벗어나는지 확인하는 함수
  return a < 0 || a >= n || b < 0 || b >= m;
}

// (x,y)에서 dir 방향으로 진행하면서 벽을 만나기 전까지의 모든 빈칸0을 7로 바꿈
void upd(int x, int y, int dir){
  dir %= 4;
  while(1){
    y += dy[dir];
    x += dx[dir];
    if(OOB(x,y) || board2[x][y] == 6) return; // 범위를 벗어났거나 벽을 만나면 함수를 탈출
    if(board2[x][y] != 0) continue; // break 아니고 continue 주의, 빈칸이 아닐 경우(=cctv가 있을 경우) 넘어감
    board2[x][y] = 7; // 빈칸을 7로 덮음
  }
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
    
  cin >> n >> m;
  
  //⭐cctv가 1개 이상이라는 말이 없음 = 0개일 수도 있음 
  // 이 때문에 ans을 0x7f7f7f7f같은 값으로 두는 것보다 직접 카운트하는 것이 안전함
  int ans = 0; // 사각 지대의 최소 크기 = 답
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> board1[i][j];
      if(board1[i][j] != 0 && board1[i][j] != 6) cctv.push_back({i,j}); // cctv 좌표
      if(board1[i][j] == 0) ans++; // 빈칸의 개수를 N*M 말고, 직접 카운트함
    }
  }
    
  // tmp를 4진법으로 뒀을 때 각 자리수를 cctv의 방향으로 생각
  // cctv가 k개 있다고 할 때 tmp는 0~4^k-1만큼 반복
  // 4^k를 쓰면 이상함, ^가 XOR임 / cmath pow()도 적합하지 않음
  // 지금은 cctv가 최대 8이라, 4^8이 double의 유효숫자 범위 내지만, 정수의 정수승은 for문으로 구현

  // 밑이 2, 4, 8처림 2의 지수일 때에는 shift를 쓸 수 있음
  // 1 << (2*cctv.size()) = 4^cctv.size()
  for(int tmp = 0; tmp < (1<<(2*cctv.size())); tmp++){ // 카메라가 3대였을 떈, 0 ~ 63
    
    // 초기 입력 받은 맵을 복사함 / 보드2는 upd에 의해 계속 바뀌고, 보드1은 원본
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++) board2[i][j] = board1[i][j];
      
    int brute = tmp;    
    for(int i = 0; i < cctv.size(); i++){ // 카메라가 3대였을 떈, 0 ~ 3
      int dir = brute % 4; // 1의 자리수 | 각 자리수가 각 카메라의 방향
      brute /= 4;          // 다음 자리수 | 다음 카메라의 방향을 알기 위해 = tmp의 값을 4진법으로 바꾸기 위해 나눔
      
      int y = cctv[i].Y; // cctv 좌표 담기
      int x = cctv[i].X; //⭐tie(x, y) = cctv[i];로 쓰면 1줄로 줄일 수 있음
      
      if(board1[x][y] == 1){
        upd(x,y,dir);
      }
      else if(board1[x][y] == 2){ 
        // 02 13을 실행해야 하는데, brute를 4진법으로 만들어서 추출한 dir이 
        // 0일땐 02, 1일땐 13, 2일땐 24, 3일땐 35를 실행
        // upd에 dir%4가 있어서 2번 캠이 갖는 2가지 방향 잘 처리
        upd(x,y,dir);
        upd(x,y,dir+2);
      }
      else if(board1[x][y] == 3){
        upd(x,y,dir);
        upd(x,y,dir+1);
      }
      else if(board1[x][y] == 4){
        upd(x,y,dir);
        upd(x,y,dir+1);
        upd(x,y,dir+2);
      }
      else{ // board1[x][y] == 5
        upd(x,y,dir);
        upd(x,y,dir+1);
        upd(x,y,dir+2);
        upd(x,y,dir+3);
      }
    }
    
    // 빈칸의 개수를 세고 ans을 갱신
    int val = 0;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        val += (board2[i][j]==0);
    ans = min(ans, val); 
  }
    
  // 모든 방향에 대해 확인한 후에는 값을 출력
  cout << ans;
  return 0;
}

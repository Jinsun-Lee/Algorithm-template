// g++ (GNU C++ 컴파일러)의 버전 정보 확인: g++ --version
// clang++ 버전 확인: clang++ --version

// 첫줄에는 w와 h가 공백을 사이에 두고 주어진다. 
// 그 다음 줄에는 초기 위치의 좌표값 p와 q가 공백을 사이에 두고 주어진다. 
// 3번째 줄에는 개미가 움직일 시간 t가 주어진다. 
#include <iostream>
using namespace std;

void calculateAntPosition(int w, int h, int p, int q, int t) {
    
    // 시간에 따른 개미의 위치 계산
    int new_p = (p + t) % (2 * w);
    int new_q = (q + t) % (2 * h);
    
    if (new_p > w) {
        new_p = 2 * w - new_p;
    }
    
    if (new_q > h) {
        new_q = 2 * h - new_q;
    }
     
    cout << new_p << " " << new_q << endl;
}
    
int main() {
    // 입력 받기
    int w, h, p, q, t;
    cin >> w >> h;          // 가로, 세로 크기 입력
    cin >> p >> q;          // 초기 위치 좌표 입력
    cin >> t;               // 움직일 시간 입력

    // 개미의 위치 계산 및 출력
    calculateAntPosition(w, h, p, q, t);

    return 0;
}
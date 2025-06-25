#include <iostream>
using namespace std;
#define TOGGLE(idx) (led[(idx)] ^= 1)

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int led[101];
    led[0] = -1;
    
    int n; cin >> n; // 스위치수
    for (int i = 1; i <= n; ++i) cin >> led[i];

    int stu, g, id; // 학생수, gender, index;
    cin >> stu;
    while (stu--) {
        cin >> g >> id; 
        
        if (g == 1) { //남1 배수전부토글
            for (int i = id; i <= n; i+=id) TOGGLE(i);
        }
        else { //여2 id기준좌우같은지확인하다,다르기전까지만토글            
            TOGGLE(id);

            for (int i = 1; id-i>=1 && id+i<=n; ++i) {
                if (led[id - i] != led[id + i]) break;
                TOGGLE(id - i);
                TOGGLE(id + i);
            }
        }
    }

    // 1번부터 20개씩 출력하고 "\n";
    for (int i = 1; i <= n; ++i) {
        cout << led[i] << " ";
        if (i % 20 == 0) cout << "\n";
    }
    return 0;
}
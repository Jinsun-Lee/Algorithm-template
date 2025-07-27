#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int tmp;
    bool asc = 1, des = 1;
    
    for (int i = 0; i < 8; ++i) {
        cin >> tmp;
        if (asc && (i + 1) != tmp) asc = false;
        if (des && (8 - i) != tmp) des = false;
        
        if (!asc && !des) {
            cout << "mixed";
            return 0;
        }
    }
    
    if (asc) cout << "ascending";
    else cout << "descending";

    return 0;
}
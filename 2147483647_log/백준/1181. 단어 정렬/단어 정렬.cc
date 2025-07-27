#include <iostream>
#include <set> 
#include <string>
#include <utility>
using namespace std;
struct shortABC {
    string name;
    bool operator < (const shortABC& other) const {
        if (name.length() == other.name.length()) {
            return name < other.name;
        }
        return name.length() < other.name.length();
    }
};

int N;
set<shortABC> alpha;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    string s;
    for (int i = 0; i < N; ++i) {
        cin >> s;
        alpha.insert({ s });
    }
    for (shortABC s : alpha) cout << s.name << "\n";
    return 0;
}
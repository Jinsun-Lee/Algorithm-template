#include <iostream>
#include <vector>
using namespace std;

string a, b;
vector<int> v;

void re(vector<int> v) {
    if (v.size() <= 2) {
        cout << v[0] << v[1];
        return;
    }

    vector<int> v2;
    for (int i = 1; i < v.size(); ++i) { 
        v2.push_back((v[i-1] + v[i]) % 10);
    }
    re(v2);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> a >> b;
    for (int i = 0; i < 8; ++i) {
        v.push_back(int(a[i] - '0'));
        v.push_back(int(b[i] - '0'));
    }

    re(v);

    return 0;
}
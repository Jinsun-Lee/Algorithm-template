#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int chk = 0;
    for (char c : s){
        if (c == '(') chk++;
        else if (c == ')') chk--;
        
        if (chk<0) return false;
    }
    if (chk!=0) return false;
    return answer;
}
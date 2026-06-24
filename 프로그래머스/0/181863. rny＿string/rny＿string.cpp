#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    int len = s.length();
    
    string ans;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'm') {
            ans += "rn";
        } else {
            ans += s[i];
        }
    }
    
    return ans;
}
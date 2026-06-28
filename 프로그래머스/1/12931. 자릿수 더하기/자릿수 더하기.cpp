#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    string s = to_string(n);
    
    int result = 0;
    for (int i = 0; i < s.length(); i++) {
        result += s[i] - '0';
    }
    
    return result;
}
#include <bits/stdc++.h>
using namespace std;

int solution(int a, int b) {
    string s = to_string(a) + to_string(b);
    
    int answer = stoi(s) > 2 * a * b ? stoi(s) : 2 * a * b;
    
    return answer;
}
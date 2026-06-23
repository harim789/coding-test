#include <bits/stdc++.h>
using namespace std;

int solution(int a, int b) {
    int answer;
    if (a & 1 && b & 1) {
        answer = pow(a, 2) + pow(b, 2);
    } else if (a & 1 || b & 1) {
        answer = 2 * (a + b);
    } else {
        answer = abs(a - b);
    }
    
    return answer;
}
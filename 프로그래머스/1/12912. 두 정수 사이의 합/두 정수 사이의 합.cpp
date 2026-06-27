#include <bits/stdc++.h>
using namespace std;

int solution(int a, int b) {
    int min = a, max = b;
    if (a >= b) {
        max = a;
        min = b;
    }
    long long result = 0;
    for (int i = min; i <= max; i++) {
        result += i;
    }
    
    return result;
}
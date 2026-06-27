#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    int result = n;
    for (int i = 1; i < n/2; i++) {
        if (n % i == 0) result += i;
    }
    
    if (n % 2 == 0) {
        result += n/2;
    }
    
    return result;
}
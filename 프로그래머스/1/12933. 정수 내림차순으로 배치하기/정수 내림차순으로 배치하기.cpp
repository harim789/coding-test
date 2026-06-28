#include <bits/stdc++.h>
using namespace std;

long long solution(long long n) {
    vector<int> v;
    
    while(n != 0) {
        v.push_back(n % 10);
        n /= 10;
    }
    
    sort(v.begin(), v.end());
    
    long long result = 0;
    int len = v.size();
    for (int i = 0; i < len; i++) {
        result *= 10;
        result += v.back();
        v.pop_back();
    }
    
    return result;
}
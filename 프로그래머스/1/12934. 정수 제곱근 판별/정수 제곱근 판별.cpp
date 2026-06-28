#include <bits/stdc++.h>
using namespace std;

long long solution(long long n) {
    long long x = sqrt(n);
    if (x * x == n) {
        return pow(x + 1, 2);
    } else {
        return -1;
    }
}
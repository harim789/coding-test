#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    int result = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            result += i;
            
            if (i * i != n) result += n / i;
        }
    }
        
    return result;
}
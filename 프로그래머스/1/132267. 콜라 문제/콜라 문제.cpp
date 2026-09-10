#include <iostream>
using namespace std;

int solution(int a, int b, int n) {
    long long total = n;
    
    int res = 0;
    while (1) {
        int quote = total / a;
        int residue = total % a;
        
        res += (quote * b);
        total = quote * b + residue;
        
        if (quote == 0) {
            return res;
        }
    }
}
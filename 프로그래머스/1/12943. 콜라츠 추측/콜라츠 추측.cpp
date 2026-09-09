#include <iostream>

int solution(int n) {
    if (n == 1) return 0;
    
    long long num = (long long) n;
    
    int count = 0;
    while(count <= 500) {
        count++;
        
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num *= 3;
            num += 1;
        }
        
        if (num == 1) return count;
    }
    
    return -1;
}
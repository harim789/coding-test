#include <iostream>
#include <vector>
using namespace std;

int solution(int number, int limit, int power) {
    vector<int> v(number + 1, 0);
    
    v[1] = 1;
    
    for (int i = 2; i <= number; i++) {
        for (long long j = 1; j * j <= i; j++) {
            if (j * j == i) {
                v[i]++;
            } else if (i % j == 0) { 
                v[i] += 2;
            }
        }
        
        // cout << i << "의 약수의 개수: " << v[i] << endl;
    }
    
    int res = 0;
    for (int i = 1; i <= number; i++) {
        if (v[i] <= limit) {
            res += v[i];
        } else {
            res += power;
        }
    }
    
    return res;
}
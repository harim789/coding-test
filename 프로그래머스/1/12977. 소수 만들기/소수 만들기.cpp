#include <iostream>
#include <vector>
using namespace std;

int sosu[3000];

void eratos() {
    sosu[0] = sosu[1] = 1;
    
    for (int i = 2; i <= 2997; i++) {
        if (!sosu[i]) {
            for (int j = i * i; j <= 2997; j += i) {
                sosu[j] = 1;
            }
        }
    }
}

int solution(vector<int> nums) {
    int result = 0;
    eratos();
    
    for (int i = 0; i < nums.size() - 2; i++) {
        for (int j = i + 1; j < nums.size() - 1; j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if (!sosu[sum]) result++;
            }
        }
    }
    
    return result;
}
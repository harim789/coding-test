#include <cmath>
using namespace std;

int solution(int left, int right) {
    int ans = 0;
    for (int i = left; i <= right; i++) {
        int sqrt_num = sqrt(i);
        if (sqrt_num * sqrt_num == i) {
            ans -= i;
        } else {
            ans += i;
        }
    }
    
    return ans;
}
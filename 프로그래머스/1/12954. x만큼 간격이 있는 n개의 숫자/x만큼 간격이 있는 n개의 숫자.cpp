#include <vector>
using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> result;
    
    for (int i = 1; i <= n; i++) {
        long long input_su = (long long)x * i;
        result.push_back(input_su);
    }
    
    return result;
}
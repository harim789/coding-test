#include <vector>
#include <numeric>
using namespace std;

vector<int> solution(int n, int m) {
    int gongyaksu = gcd(n, m);
    int gongbasu = lcm(n, m);
    
    vector<int> ans;
    ans.push_back(gongyaksu);
    ans.push_back(gongbasu);
    
    return ans;
}
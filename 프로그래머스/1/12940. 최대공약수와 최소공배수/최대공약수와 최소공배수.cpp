#include <vector>
using namespace std;

int gcd(int n, int m) {
    while(m != 0) {
        int r = n % m;
        n = m;
        m = r;
    }
    return n;
}

int lcm(int n, int m) {
    return n * m / gcd(n, m);
}

vector<int> solution(int n, int m) {
    vector<int> ans;
    ans.push_back(gcd(n, m));
    ans.push_back(lcm(n, m));
    
    return ans;
}
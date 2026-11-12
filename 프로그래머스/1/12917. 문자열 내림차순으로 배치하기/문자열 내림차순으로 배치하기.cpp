#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    vector<char> v_small;
    vector<char> v_big;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            v_small.push_back(s[i]);
        } else {
            v_big.push_back(s[i]);
        }
    }
    
    sort(v_small.begin(), v_small.end());
    reverse(v_small.begin(), v_small.end());
    sort(v_big.begin(), v_big.end());
    reverse(v_big.begin(), v_big.end());
    
    string ans;
    
    for (int i = 0; i < v_small.size(); i++) {
        ans += v_small[i];
    }
    
    for (int i = 0; i < v_big.size(); i++) {
        ans += v_big[i];
    }
    
    return ans;
}
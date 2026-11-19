#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(string s) {
    int size = s.size();
    
    vector<int> ans(size, -1);
    
    for (int i = 1; i < size; i++) {
        for (int j = i - 1; j >= 0; j--) {
            // cout << s[i] << ' ' << s[j] << endl;
            if (s[i] == s[j]) {
                ans[i] = i - j;
                break;
            }
        }
    }
    
    return ans;
}
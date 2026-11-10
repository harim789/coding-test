#include <string>
using namespace std;

string solution(string str) {
    int len = str.size();
    int idx = len / 2;
    
    string ans = "";
    if (len % 2 == 0) {
        ans += str[idx - 1];
        ans += str[idx];
    } else {
        ans += str[idx];
    }
    
    return ans;
}
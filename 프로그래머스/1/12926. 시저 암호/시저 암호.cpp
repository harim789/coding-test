#include <string>
using namespace std;

string solution(string s, int n) {
    int len = s.size();
    
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < n; j++) {
            if ((s[i] >= 'a' && s[i] < 'z') ||  (s[i] >= 'A' && s[i] < 'Z')) {
                s[i]++;
            } else if (s[i] == 'z') {
                s[i] = 'a';
            } else if (s[i] == 'Z') {
                s[i] = 'A';
            }
        }
    }
    
    return s;
}
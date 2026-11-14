// #include <string>
// using namespace std;

// string solution(string s) {
//     int idx = 0;
//     int len = s.length();
    
//     for (int i = 0; i < len; i++) {
//         if (s[i] == ' ') {
//             idx = 0;
//             continue;
//         }
//         if (idx % 2 == 0) {
//             s[i].upper();
//         }
//         idx++;
//     }
    
//     return s;
// }

#include <string>
#include <iostream>
using namespace std;

string solution(string s) {
    int idx = 0;
    int len = s.length();
    
    // int a = 'a';
    // int A = 'A';
    // cout << a << ' ' << A << endl;
    // 아스키코드 숫자
    // a: 97
    // A: 65
    
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') {
            idx = 0;
            continue;
        }
        if (idx % 2 == 0 && s[i] >= 'a' && s[i] <= 'z') {
            s[i] -= 32;
        } else if (idx % 2 == 1 && s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 32;
        }
        idx++;
    }
    
    return s;
}
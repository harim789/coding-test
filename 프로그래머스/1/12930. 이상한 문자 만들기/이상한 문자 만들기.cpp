// toupper('a')
// tolower('A')

// (추가로 알아두면 좋은 것)
// 아스키코드 
// a: 97
// A: 65

#include <string>
using namespace std;

string solution(string s) {
    int idx = 0;
    int len = s.length();
    
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') {
            idx = 0;
            continue;
        }
        if (idx % 2 == 0) {
            s[i] = toupper(s[i]);
            // toupper(s[i])만 하면 안 됨.
            // toupper(s[i]) 한 것을 s[i]에 넣어줘야 함!
        } else {
            s[i] = tolower(s[i]);
        }
        idx++;
    }
    
    return s;
}

// #include <string>
// #include <iostream>
// using namespace std;

// string solution(string s) {
//     int idx = 0;
//     int len = s.length();
    
//     // int a = 'a';
//     // int A = 'A';
//     // cout << a << ' ' << A << endl;
//     // 아스키코드 숫자
//     // a: 97
//     // A: 65
    
//     for (int i = 0; i < len; i++) {
//         if (s[i] == ' ') {
//             idx = 0;
//             continue;
//         }
//         if (idx % 2 == 0 && s[i] >= 'a' && s[i] <= 'z') {
//             s[i] -= 32;
//         } else if (idx % 2 == 1 && s[i] >= 'A' && s[i] <= 'Z') {
//             s[i] += 32;
//         }
//         idx++;
//     }
    
//     return s;
// }
#include <bits/stdc++.h>
using namespace std;

string solution(string n_str) {
    int cnt = 0;
    for (char c: n_str) {
        if (c != '0') {
            break;
        } else {
            cnt++;
        }
    }
    
    string answer = "";
    if (cnt) {
        for (int i = cnt; i < n_str.length(); i++) {
            answer += n_str[i];
        } 
    } else {
        answer = n_str;
    }

    return answer;
}
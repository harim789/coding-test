#include <bits/stdc++.h>
using namespace std;

string solution(string n_str) {
    int offset = 0;
    for (char c: n_str) {
        if (c != '0') {
            break;
        } else {
            offset++;
        }
    }

    return n_str.substr(offset);
}
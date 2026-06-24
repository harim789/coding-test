#include <bits/stdc++.h>
using namespace std;

int solution(string myString, string pat) {
    for (int i = 0; i < pat.length(); i++) {
        if (pat[i] == 'A') {
            pat[i] = 'B';
        } else {
            pat[i] = 'A';
        }
    }
    
    if (myString.find(pat) != string::npos) {
        return 1;
    } else {
        return 0;
    }
}
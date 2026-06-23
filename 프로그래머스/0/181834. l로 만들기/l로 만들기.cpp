#include <bits/stdc++.h>
using namespace std;

string solution(string myString) {
    for (auto& c: myString) {
        c = c < 'l' ? 'l' : c;
    }
    
    return myString;
}
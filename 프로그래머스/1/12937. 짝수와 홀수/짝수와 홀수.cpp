#include <bits/stdc++.h>
using namespace std;

string solution(int num) {
    if (num & 1) {
        return "Odd";
    } else {
        return "Even";
    }
}
#include <bits/stdc++.h>
using namespace std;

int solution(string binomial) {
    stringstream ss(binomial);
    
    int su1, su2;
    char op;
    
    ss >> su1 >> op >> su2;
    
    int result;
    switch(op) {
        case '+':
            result = su1 + su2;
            break;
        case '-':
            result = su1 - su2;
            break;
        case '*':
            result = su1 * su2;
            break;
    }
    
    return result;
}
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> X;
    
    for (int i: arr) {
        X.insert(X.end(), i, i);
    }
    
    return X;
}
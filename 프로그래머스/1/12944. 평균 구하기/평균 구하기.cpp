#include <bits/stdc++.h>
using namespace std;

double solution(vector<int> arr) {
    double sum = accumulate(arr.begin(), arr.end(), 0);
    
    double result = sum / (float)arr.size();
    
    return result;
}
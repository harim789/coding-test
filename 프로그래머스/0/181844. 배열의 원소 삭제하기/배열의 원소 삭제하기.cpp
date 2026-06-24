#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    for (int i: delete_list) {
        arr.erase(remove_if(arr.begin(), arr.end(), [i](int x){ return x == i; }), arr.end());
    }
    
    return arr;
}
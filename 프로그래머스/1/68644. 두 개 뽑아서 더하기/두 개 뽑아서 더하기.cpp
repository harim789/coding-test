#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    
    vector<int> add;
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            add.push_back(numbers[i] + numbers[j]);
        }
    }
    
    sort(add.begin(), add.end());
    vector<int> ans;
    ans.push_back(add[0]);
    
    for (int i = 1; i < add.size(); i++) {
        if (add[i] != add[i - 1]) {
            ans.push_back(add[i]);
        }
    }
    
    return ans;
}
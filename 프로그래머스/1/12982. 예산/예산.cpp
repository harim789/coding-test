#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int> d, int budget) {
    sort(d.begin(), d.end());
    
    int res = 0;
    for (int i = 0; i < d.size(); i++) {
        if (budget >= d[i]) {
            budget -= d[i];
            res++;
        } else {
            break;
        }
    }
    
    return res;
}
#include <algorithm>
#include <vector>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> res;
    
    for (vector<int> c: commands) {
        vector<int> v;
        
        for (int i = c[0] - 1; i <= c[1] - 1; i++) {
            v.push_back(array[i]);
        }
        
        sort(v.begin(), v.end());
        res.push_back(v[c[2] - 1]);
    }
    
    return res;
}
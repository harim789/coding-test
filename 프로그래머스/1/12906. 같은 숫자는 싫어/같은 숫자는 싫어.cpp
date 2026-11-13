#include <vector>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> ans;
    ans.push_back(arr[0]);
    
    int idx = 1;
    for (int i = 1; i < arr.size(); i++) {
        if (ans[idx - 1] != arr[i]) {
            ans.push_back(arr[i]);
            idx++;
        }
    }
    
    return ans;
}
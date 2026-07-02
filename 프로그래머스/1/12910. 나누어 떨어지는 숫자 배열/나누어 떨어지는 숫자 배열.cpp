#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> result;
    
    for (int i = 0; i < arr.size(); i++) {
        if (!(arr[i] % divisor)) {
            result.push_back(arr[i]);
        }
    }
    
    sort(result.begin(), result.end());
    
    if (!(result.size())) {
        result.push_back(-1);
    }
    
    return result;
}
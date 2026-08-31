#include <vector>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> result;
    int s = arr.size();
    
    if (s == 1) {
        result.push_back(-1);
        return result;
    }
    
    
    int min = arr[0];
    int min_index = 0;
    for (int i = 1; i < s; i++) {
        if (min > arr[i]) {
            min = arr[i];
            min_index = i;
        }
    }
    
    for (int i = 0; i < s; i++) {
        if (i == min_index) continue;
        
        result.push_back(arr[i]);
    }
    
    return result;
}
#include <vector>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int max_w = sizes[0][0] > sizes[0][1] ? sizes[0][0] : sizes[0][1];
    int max_h = sizes[0][0] > sizes[0][1] ? sizes[0][1] : sizes[0][0];
    
    for (int i = 1; i < sizes.size(); i++) {
        if (sizes[i][0] < sizes[i][1]) swap(sizes[i][0], sizes[i][1]);
        
        if (sizes[i][0] > max_w) max_w = sizes[i][0];
        if (sizes[i][1] > max_h) max_h = sizes[i][1];
    }
    
    return max_w * max_h;
}
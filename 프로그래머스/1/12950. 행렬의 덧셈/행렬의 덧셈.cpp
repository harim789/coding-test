#include <vector>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int r_size = arr1.size();
    int c_size = arr2[0].size();
    
    vector<vector<int>> mat(r_size);
    for (int i = 0; i < r_size; i++) {
        mat[i].resize(c_size);
    }
    
    for (int i = 0; i < r_size; i++) {
        for (int j = 0; j < c_size; j++) {
            mat[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    
    return mat;
}
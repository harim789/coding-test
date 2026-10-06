#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> mat(n);
    for (int i = 0; i < n; i++) {
        mat[i].resize(n);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    int maximum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 2; j++) {
            maximum = max(maximum, mat[i][j] + mat[i][j + 1] + mat[i][j + 2]);
        }
    }

    cout << maximum;

    return 0;
}
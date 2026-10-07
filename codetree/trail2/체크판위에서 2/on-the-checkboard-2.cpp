#include <iostream>
#include <vector>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;

    vector<vector<char>> mat(r);
    for (int i = 0; i < r; i++) {
        mat[i].resize(c);
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mat[i][j];
        }
    }

    int cur_r = 0;
    int cur_c = 0;

    int cnt = 0;
    for (int i = 1; i < r - 1; i++) {
        for (int j = 1; j < c - 1; j++) {
            for (int k = i + 1; k < r - 1; k++) {
                for (int l = j + 1; l < c - 1; l++) {
                    if (mat[0][0] != mat[i][j] && mat[i][j] != mat[k][l] && mat[k][l] != mat[r - 1][c - 1]) cnt++;
                }
            }
        }
    }

    cout << cnt;

    return 0;
}
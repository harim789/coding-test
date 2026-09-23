#include <iostream>
#include <vector>
using namespace std;

int main() {
    int x1[3], x2[3];
    int y1[3], y2[3];

    cin >> x1[0] >> y1[0] >> x2[0] >> y2[0];
    cin >> x1[1] >> y1[1] >> x2[1] >> y2[1];
    cin >> x1[2] >> y1[2] >> x2[2] >> y2[2];

    vector<vector<int>> mat(2000);
    for (int i = 0; i < 2000; i++) {
        mat[i].resize(2000, 0);
    }

    for (int i = x1[0]; i < x2[0]; i++) {
        for (int j = y1[0]; j < y2[0]; j++) {
            mat[i + 1000][j + 1000] = 1;
        }
    }

    for (int i = x1[1]; i < x2[1]; i++) {
        for (int j = y1[1]; j < y2[1]; j++) {
            mat[i + 1000][j + 1000] = 1;
        }
    }

    for (int i = x1[2]; i < x2[2]; i++) {
        for (int j = y1[2]; j < y2[2]; j++) {
            mat[i + 1000][j + 1000] = 2;
        }
    }

    int cnt = 0;
    for (int i = 0; i < 2000; i++) {
        for (int j = 0; j < 2000; j++) {
            if (mat[i][j] == 1) cnt++;
        }
    }

    cout << cnt;

    return 0;
}
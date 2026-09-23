#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    int x1[10], x2[10];
    int y1[10], y2[10];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }

    vector<vector<int>> mat(201);
    for (int i = 0; i < 200; i++) {
        mat[i].resize(201, 0);
    }

    for (int i = 0; i < n; i++) {
        for (int j = x1[i]; j < x2[i]; j++) {
            for (int k = y1[i]; k < y2[i]; k++) {
                mat[j + 100][k + 100] = 1;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            if (mat[i][j] == 1) cnt++;
        }
    }

    cout << cnt;

    return 0;
}
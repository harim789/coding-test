#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    
    int x[100];
    int y[100];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    vector<vector<int>> mat(200);
    for (int i = 0; i < 200; i++) {
        mat[i].resize(200, 0);
    }

    for (int i = 0; i < n; i++) {
        for (int j = x[i]; j < x[i] + 8; j++) {
            for (int k = y[i]; k < y[i] + 8; k++) {
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
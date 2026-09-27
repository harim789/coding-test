#include <iostream>
using namespace std;

int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

int n;

bool inRange(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

int main() {
    cin >> n;

    int mat[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    int cnt = 0;
    int each_cnt;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            each_cnt = 0;
            for (int d = 0; d < 4; d++) {
                int nx = i + dir_x[d];
                int ny = j + dir_y[d];

                if (inRange(nx, ny) && mat[nx][ny] == 1) {
                    each_cnt++;
                }
            }

            if (each_cnt >= 3) cnt++;
        }
    }

    cout << cnt;

    return 0;
}
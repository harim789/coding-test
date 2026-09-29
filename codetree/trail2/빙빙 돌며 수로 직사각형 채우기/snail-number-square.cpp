#include <iostream>
using namespace std;

int dir_r[4] = {0, 1, 0, -1};
int dir_c[4] = {1, 0, -1, 0};

int n, m;

bool inRange(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < m);
}

int main() {
    cin >> n >> m;

    int mat[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mat[i][j] = 0;
        }
    }

    int cur_r = 0;
    int cur_c = 0;

    int fill = 1;
    int dir = 0;

    mat[0][0] = fill;

    for (int i = 1; i < n * m; i++) {
        fill++;

        int nr = cur_r + dir_r[dir];
        int nc = cur_c + dir_c[dir];

        if (inRange(nr, nc) && mat[nr][nc] == 0) {
            mat[nr][nc] = fill;

            cur_r += dir_r[dir];
            cur_c += dir_c[dir];
        } else {
            dir = (dir + 1) % 4;

            cur_r += dir_r[dir];
            cur_c += dir_c[dir];

            mat[cur_r][cur_c] = fill;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
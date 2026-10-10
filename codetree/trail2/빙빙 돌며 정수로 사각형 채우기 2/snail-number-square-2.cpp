#include <iostream>
#include <vector>
using namespace std;

int n, m;

int dir_r[4] = {1, 0, -1, 0};
int dir_c[4] = {0, 1, 0, -1};

bool inRange(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < m);
}

int main() {
    cin >> n >> m;

    vector<vector<int>> mat(n);
    for (int i = 0; i < n; i++) {
        mat[i].resize(m, 0);
    }

    int cur_r = 0;
    int cur_c = 0;

    int num = 1;

    mat[0][0] = num;

    int cur_dir = 0;

    for (int i = 0; i < n * m - 1; i++) {
        num++;

        int next_r = cur_r + dir_r[cur_dir];
        int next_c = cur_c + dir_c[cur_dir];

        if (!inRange(next_r, next_c) || mat[next_r][next_c] != 0) {
            cur_dir = (cur_dir + 1) % 4;

            next_r = cur_r + dir_r[cur_dir];
            next_c = cur_c + dir_c[cur_dir];

            //cout << "막힘" << cur_dir << ' ' << cur_r << ' ' << cur_c <<  ' ' << num << endl;
        }

        mat[next_r][next_c] = num;

        cur_r = next_r;
        cur_c = next_c;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
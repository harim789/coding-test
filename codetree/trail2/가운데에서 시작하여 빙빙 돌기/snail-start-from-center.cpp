#include <iostream>
#include <vector>
using namespace std;

int dir_r[4] = {0, -1, 0, 1};
int dir_c[4] = {1, 0, -1, 0};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> mat(n);
    for (int i = 0; i < n; i++) {
        mat[i].resize(n, 0);
    }

    int cur_r = n / 2;
    int cur_c = n / 2;

    int cur_num = 1;

    mat[cur_r][cur_c] = cur_num;

    if (n != 1) {
        cur_num++;
        cur_c++;
        mat[cur_r][cur_c] = cur_num;
    }

    int cur_dir = 0;

    for (int i = 0; i < n * n - 2; i++) {
        cur_num++;

        int turn_dir = (cur_dir + 1) % 4;
        int turn_r = cur_r + dir_r[turn_dir];
        int turn_c = cur_c + dir_c[turn_dir];

        if (mat[turn_r][turn_c] == 0) {
            cur_r = turn_r;
            cur_c = turn_c;
            cur_dir = turn_dir;
        } else {
            // cout << cur_r << ' ' << cur_c << endl;
            // cout << cur_num << endl;
            // cout << cur_dir << endl;
            cur_r += dir_r[cur_dir];
            cur_c += dir_c[cur_dir];
            //cout << cur_r << ' ' << cur_c << endl;
        }

        mat[cur_r][cur_c] = cur_num;

        // cout << "mat[" << cur_r << "][" << cur_c << "] = " << cur_num << "저장" << endl;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
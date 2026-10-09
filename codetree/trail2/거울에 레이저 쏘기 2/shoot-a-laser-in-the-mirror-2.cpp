#include <iostream>
#include <vector>
using namespace std;

int n;

bool inRange(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < n);
}

int out_dir(char slash, int come_dir) {
    if (slash == '/') {
        if (come_dir == 0) {
            return 1;
        } else if (come_dir == 1) {
            return 0;
        } else if (come_dir == 2) {
            return 3;
        } else {
            return 2;
        }
    } else {
        if (come_dir == 0) {
            return 3;
        } else if (come_dir == 1) {
            return 2;
        } else if (come_dir == 2) {
            return 1;
        } else {
            return 0;
        }
    }
}

int main() {
    cin >> n;

    vector<vector<char>> mat(n);
    for (int i = 0; i < n; i++) {
        mat[i].resize(n);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    int k;
    cin >> k;

    int cur_dir = (k - 1) / n;
    int next_r;
    int next_c;

    if ((k - 1) / n == 0) {
        next_r = 0;
        next_c = (k - 1) % n;
    } else if ((k - 1) / n == 1) {
        next_r = (k - 1) % n;
        next_c = n - 1;
    } else if ((k - 1) / n == 2) {
        next_r = n - 1;
        int tmp = (k - 1) % n;
        next_c = (n - 1) - tmp;
    } else if ((k - 1) / n == 3) {
        int tmp = (k - 1) % n;
        next_r = (n - 1) - tmp;
        next_c = 0;
    }

    int cnt = 0;
    while(inRange(next_r, next_c)) {
        cnt++;
        int next_come_dir = out_dir(mat[next_r][next_c], cur_dir);
        if (next_come_dir == 0) {
            next_r++;
        } else if (next_come_dir == 1) {
            next_c--;
        } else if (next_come_dir == 2) {
            next_r--;
        } else if (next_come_dir == 3) {
            next_c++;
        }
        cur_dir = next_come_dir;

        //cout << cur_dir << ' ' << next_r << ' ' << next_c << endl;
    }

    cout << cnt;

    return 0;
}
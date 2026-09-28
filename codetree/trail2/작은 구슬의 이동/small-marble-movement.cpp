#include <iostream>
using namespace std;

int dir_r[4] = {0, 1, 0, -1};
int dir_c[4] = {1, 0, -1, 0};

int n;

bool inRange(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= n);
}

int main() {
    int t;
    cin >> n >> t;

    int r, c;
    char d;
    cin >> r >> c >> d;

    int dir;
    if (d == 'U') {
        dir = 3;
    } else if (d == 'R') {
        dir = 0;
    } else if (d == 'D') {
        dir = 1;
    } else {
        dir = 2;
    }

    int cur_r = r;
    int cur_c = c;
    for (int i = 0; i < t; i++) {
        int nr = cur_r + dir_r[dir];
        int nc = cur_c + dir_c[dir];

        if (!inRange(nr, nc)) {
            dir = (dir + 2) % 4;
        } else {
            cur_r = nr;
            cur_c = nc;
        }

        //cout << cur_r << ' ' << cur_c << ' ' << dir << endl;
    }

    cout << cur_r << ' ' << cur_c;

    return 0;
}
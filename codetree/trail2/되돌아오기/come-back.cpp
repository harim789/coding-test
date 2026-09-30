#include <iostream>
using namespace std;

int dir_char_to_num(char dir_char) {
    if (dir_char == 'E') {
        return 0;
    } else if (dir_char == 'S') {
        return 1;
    } else if (dir_char == 'W') {
        return 2;
    } else {
        return 3;
    }
}

int main() {
    int n;
    cin >> n;

    int dir_r[4] = {0, 1, 0, -1};
    int dir_c[4] = {1, 0, -1, 0};

    char dir_char[n];
    int dist[n];

    for (int i = 0; i < n; i++) {
        cin >> dir_char[i] >> dist[i];
    }

    int cur_r = 1000;
    int cur_c = 1000;

    int mat[2000][2000];

    int cnt = 0;
    bool exist = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < dist[i]; j++) {
            cnt++;

            int dir_num = dir_char_to_num(dir_char[i]);

            cur_r += dir_r[dir_num];
            cur_c += dir_c[dir_num];

            if (cur_r == 1000 && cur_c == 1000) {
                exist = true;
                cout << cnt;

                return 0;
            }

            //cout << cur_r << ' ' << cur_c << endl;
        }
    }

    if (!exist) cout << -1;

    return 0;
}
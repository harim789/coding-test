#include <iostream>
using namespace std;

int main() {
    string str;
    cin >> str;

    int dir_r[4] = {-1, 0, 1, 0};
    int dir_c[4] = {0, 1, 0, -1};

    int cur_dir = 0;
    int cur_r = 100000;
    int cur_c = 100000;

    int cnt = 1;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'L') {
            cur_dir = (cur_dir + 3) % 4;
        } else if (str[i] == 'R') {
            cur_dir = (cur_dir + 1) % 4;
        } else {
            cur_r += dir_r[cur_dir];
            cur_c += dir_c[cur_dir];
        }

        if (cur_r == 100000 && cur_c == 100000) {
            cout << cnt;
            return 0;
        }

        cnt++;
    }

    cout << -1;

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

int main() {
    string str;
    cin >> str;

    int cur_x = 0;
    int cur_y = 0;

    int cur_dir = 0;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'L') {
            cur_dir = (cur_dir + 3) % 4;
        } else if (str[i] == 'R') {
            cur_dir = (cur_dir + 1) % 4;
        } else {
            cur_x += dir_x[cur_dir];
            cur_y += dir_y[cur_dir];
        }
    }

    cout << cur_x << ' ' << cur_y;

    return 0;
}
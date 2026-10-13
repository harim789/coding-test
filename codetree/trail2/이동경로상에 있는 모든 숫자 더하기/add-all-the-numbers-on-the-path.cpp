#include <iostream>
#include <vector>
using namespace std;

int dir_r[4] = {-1, 0, 1, 0};
int dir_c[4] = {0, 1, 0, -1};

int n;

bool inRange(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < n);
}

int main() {
    int t;
    cin >> n >> t;

    string str;
    cin >> str;

    vector<vector<int>> grid(n);
    for (int i = 0; i < n; i++) {
        grid[i].resize(n);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int cur_r = n / 2;
    int cur_c = n / 2;
    int cur_dir = 0;

    int sum = grid[cur_r][cur_c];

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'R') {
            cur_dir = (cur_dir + 1) % 4;
        } else if (str[i] == 'L') {
            cur_dir = (cur_dir + 3) % 4;
        } else {
            int tmp_r = cur_r + dir_r[cur_dir];
            int tmp_c = cur_c + dir_c[cur_dir];

            if (inRange(tmp_r, tmp_c)) {
                sum += grid[tmp_r][tmp_c];
                cur_r = tmp_r;
                cur_c = tmp_c;
            }
        }
    }

    cout << sum;

    return 0;
}
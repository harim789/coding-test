#include <iostream>
#include <vector>
using namespace std;

int dir_x[4] = {1, 0, -1, 0};
int dir_y[4] = {0, -1, 0, 1};

int main() {
    int n;
    cin >> n;

    vector<char> dir(n);
    vector<int> dist(n);

    for (int i = 0; i < n; i++) {
        cin >> dir[i] >> dist[i];
    }

    int cur_x = 0;
    int cur_y = 0;

    for (int i = 0; i < n; i++) {
        if (dir[i] == 'E') {
            for (int j = 0; j < dist[i]; j++) {
                cur_x += dir_x[0];
                cur_y += dir_y[0];
            }
        } else if (dir[i] == 'S') {
            for (int j = 0; j< dist[i]; j++) {
                cur_x += dir_x[1];
                cur_y += dir_y[1];
            }
        } else if (dir[i] == 'W') {
            for (int j = 0; j < dist[i]; j++) {
                cur_x += dir_x[2];
                cur_y += dir_y[2];
            }
        } else {
            for (int j = 0; j < dist[i]; j++) {
                cur_x += dir_x[3];
                cur_y += dir_y[3];
            }
        }
    }

    cout << cur_x << ' ' << cur_y;

    return 0;
}
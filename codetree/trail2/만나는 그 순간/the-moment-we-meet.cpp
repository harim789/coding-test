#include <iostream>
using namespace std;

int main() {
    int n, m;

    int a[1000];
    char dir_a[1000];
    int b[1000];
    char dir_b[1000];

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> dir_a[i] >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> dir_b[i] >> b[i];
    }

    int a_pos[2000000];
    int a_cur = 1000;
    int time = 1;

    for (int i = 0; i < n; i++) {
        if (dir_a[i] == 'L') {
            for (int j = 1; j <= a[i]; j++) {
                a_pos[time] = a_cur - j;
                time++;
            }
            a_cur -= a[i];
        } else {
            for (int j = 1; j <= a[i]; j++) {
                a_pos[time] = a_cur + j;
                time++;
            }
            a_cur += a[i];
        }
    }

    int time_min = time;

    int b_pos[2000000];
    int b_cur = 1000;
    time = 1;

    for (int i = 0; i < m; i++) {
        if (dir_b[i] == 'L') {
            for (int j = 1; j <= b[i]; j++) {
                b_pos[time] = b_cur - j;
                time++;
            }
            b_cur -= b[i];
        } else {
            for (int j = 1; j <= b[i]; j++) {
                b_pos[time] = b_cur + j;
                time++;
            }
            b_cur += b[i];
        }
    }

    if (time_min > time) time_min = time;
    bool contact = false;

    for (int i = 1; i < time_min; i++) {
        if (a_pos[i] == b_pos[i]) {
            contact = true;
            cout << i;
            break;
        }
    }

    if (!contact) {
        cout << -1;
    }

    return 0;
}
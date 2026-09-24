#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> av(n, 0);
    vector<int> at(n, 0);
    vector<int> bv(m, 0);
    vector<int> bt(m, 0);

    for (int i = 0; i < n; i++) {
        cin >> av[i] >> at[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> bv[i] >> bt[i];
    }

    vector<int> a_pos(1000000, 0);
    int a_cur = 0;
    int time = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < at[i]; j++) {
            a_cur += av[i];
            a_pos[time] = a_cur;
            time++;
        }
    }

    int b_pos[1000000] = {0};
    int b_cur = 0;
    time = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < bt[i]; j++) {
            b_cur += bv[i];
            b_pos[time] = b_cur;
            time++;
        }
    }

    bool a_first;
    
    for (int i = 1; i < time; i++) {
        if (a_pos[i] != b_pos[i]) {
            if (a_pos[i] > b_pos[i]) {
                a_first = true;
                break;
            } else {
                a_first = false;
                break;
            }
        }
    }

    int cnt = 0;

    for (int i = 1; i < time; i++) {
        if (a_first) {
            if (a_pos[i] < b_pos[i]) {
                cnt++;
                a_first = false;
            }
        } else {
            if (a_pos[i] > b_pos[i]) {
                cnt++;
                a_first = true;
            }
        }
    }

    cout << cnt;

    return 0;
}
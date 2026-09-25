#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);
    
    vector<char> a_dir(n);
    vector<char> b_dir(m);

    int a_total_time = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> a_dir[i];
        a_total_time += a[i];
    }

    int b_total_time = 0;
    for (int i = 0; i < m; i++) {
        cin >> b[i] >> b_dir[i];
        b_total_time += b[i];
    }

    vector<int> a_pos(2000000, 0);
    vector<int> b_pos(2000000, 0);

    int a_cur = 0;
    int time = 0;
    for (int i = 0; i < n; i++) {
        if (a_dir[i] == 'L') {
            for (int j = 0; j < a[i]; j++) {
                time++;
                a_pos[time] = (a_cur - j - 1);
            }
            a_cur -= a[i];
        } else {
            for (int j = 0; j < a[i]; j++) {
                time++;
                a_pos[time] = (a_cur + j + 1);
            }
            a_cur += a[i];
        }
    }

    int b_cur = 0;
    time = 0;
    for (int i = 0; i < m; i++) {
        if (b_dir[i] == 'L') {
            for (int j = 0; j < b[i]; j++) {
                time++;
                b_pos[time] = (b_cur - j - 1);
            }
            b_cur -= b[i];
        } else {
            for (int j = 0; j < b[i]; j++) {
                time++;
                b_pos[time] = (b_cur + j + 1);
            }
            b_cur += b[i];
        }
    }

    if (a_total_time > b_total_time) {
        for (int i = b_total_time + 1; i <= a_total_time; i++) {
            b_pos[i] = b_pos[b_total_time];
        }
    } else {
        for (int i = a_total_time + 1; i <= b_total_time; i++) {
            a_pos[i] = a_pos[a_total_time];
        }
    }

    int max_time = a_total_time;
    if (a_total_time < b_total_time) max_time = b_total_time;

    int cnt = 0;
    for (int i = 1; i <= max_time; i++) {
        if (a_pos[i] == b_pos[i] && a_pos[i - 1] != b_pos[i - 1]) {
            cnt++;
        }
        //cout << a_pos[i] << ' ' << b_pos[i] << endl;
    }

    cout << cnt;

    return 0;
}
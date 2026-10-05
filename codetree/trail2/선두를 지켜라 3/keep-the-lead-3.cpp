#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v1(n);
    vector<int> t1(n);

    vector<int> v2(m);
    vector<int> t2(m);

    int total_time = 0;
    for (int i = 0; i < n; i++) {
        cin >> v1[i] >> t1[i];
        total_time += t1[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> v2[i] >> t2[i];
    }

    vector<int> loc_1(total_time + 1, 0);
    vector<int> loc_2(total_time + 1, 0);

    int time = 0;
    int cur_loc = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < t1[i]; j++) {
            time++;
            cur_loc += v1[i];
            loc_1[time] = cur_loc;
        }
    }

    time = 0;
    cur_loc = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < t2[i]; j++) {
            time++;
            cur_loc += v2[i];
            loc_2[time] = cur_loc;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= total_time; i++) {
        if ((loc_1[i - 1] < loc_2[i - 1]) && (loc_1[i] >= loc_2[i])) {
            cnt++;
        } else if ((loc_1[i - 1] == loc_2[i - 1]) && (loc_1[i] != loc_2[i])) {
            cnt++;
        } else if ((loc_1[i - 1] > loc_2[i - 1]) && (loc_1[i] <= loc_2[i])) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}
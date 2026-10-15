// pair 사용법 익혀두기!

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        v[i] = make_pair(x, y);
    }

    vector<int> each_sum(n - 1);
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n; j++) {
            if (i == j) {
                continue;
            } else if (j == i + 1) {
                each_sum[i] += (abs(v[j].first - v[j - 2].first) + abs(v[j].second - v[j - 2].second));
                // cout << abs(v[j].first - v[j - 2].first) << " + " << abs(v[j].second - v[j - 2].second) << endl;
            } else {
                each_sum[i] += (abs(v[j].first - v[j - 1].first) + abs(v[j].second - v[j - 1].second));
                // cout << abs(v[j].first - v[j - 1].first) << " + " << abs(v[j].second - v[j - 1].second) << endl;
            }
        }
        // cout << each_sum[i] << endl;
    }

    int min = INT_MAX;
    for (int i = 1; i < n - 1; i++) {
        if (min > each_sum[i]) min = each_sum[i];
    }

    cout << min;

    return 0;
}


// 이걸로 첫번째 통과(pair 못 씀ㅠ)
// int main() {
//     int n;
//     cin >> n;

//     vector<int> x(n);
//     vector<int> y(n);

//     for (int i = 0; i < n; i++) {
//         cin >> x[i] >> y[i];
//         // cout << x[i] << ' ' << y[i] << endl;
//     }

//     vector<int> each_sum(n - 1);

//     for (int i = 1; i < n - 1; i++) {
//         for (int j = 1; j < n; j++) {
//             if (j == i) {
//                 continue;
//             } else if (j == i + 1) {
//                 each_sum[i] += (abs(x[j] - x[j - 2]) + abs(y[j] - y[j - 2]));
//                 //cout << abs(x[j] - x[j - 2]) << " + " << abs(y[j] - y[j - 2]) << " = " << each_sum[i] << endl;
//             } else {
//                 each_sum[i] += (abs(x[j] - x[j - 1]) + abs(y[j] - y[j - 1]));
//                 //cout << abs(x[j] - x[j - 1]) << " + " << abs(y[j] - y[j - 1]) << " = " << each_sum[i] << endl;
//             }
//         }
//     }

//     int min = INT_MAX;
//     for (int i = 1; i < n - 1; i++) {
//         if (min > each_sum[i]) min = each_sum[i];
//     }

//     cout << min;

//     return 0;
// }
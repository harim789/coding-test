#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second > b.second;
    } else {
        return a.first < b.first;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, b;
    cin >> n >> m >> b;
    int A[n][m];

    int min = 256;
    int max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int a;
            cin >> a;
            A[i][j] = a;

            if (a < min) min = a;
            if (a > max) max = a;
        }
    }

    int sec;
    int block;
    vector<pair<int, int>> B;
    int height = min;
    while (1) {
        // cout << "height: " << height << '\n';

        sec = 0;
        block = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (A[i][j] > height) {
                    sec += (A[i][j] - height) * 2;
                    block += (A[i][j] - height);

                    // cout << "A[" << i << "][" << j << "] > height(" << height << ")" << '\n';
                    // cout << "sec: " << sec << '\n';
                } else if (A[i][j] < height) {
                    sec += (height - A[i][j]);
                    block -= (height - A[i][j]);

                    // cout << "A[" << i << "][" << j << "] < height(" << height << ")" << '\n';
                    // cout << "sec: " << sec << '\n';
                }
            }
        }

        if ((b + block) >= 0) {
            B.push_back(make_pair(sec, height));
            height++;

            // cout << "b + block: " << b + block << '\n';
        } else if (((b + block) < 0) || height >= max) {
            break;
        }
    }
    sort(B.begin(), B.end(), compare);

    cout << B[0].first << ' ' << B[0].second << '\n';
}
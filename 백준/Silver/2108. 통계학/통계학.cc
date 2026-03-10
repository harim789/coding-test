#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    } else {
        return a.first > b.first;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> A(n, {0, 4001});
    vector<int> B(n);

    int su_num = 0;
    for (int i = 0; i < n; i++) {
        int su;
        cin >> su;

        B[i] = su;

        bool isExist = false;
        for (int j = 0; j < i; j++) {
            if (su == A[j].second) {
                isExist = true;
                A[j].first++;
                break;
            }
        }
        if (!isExist) {
            A[su_num].first = 1;
            A[su_num].second = su;
            su_num++;
        }
    }

    sort(A.begin(), A.begin() + su_num, compare);
    sort(B.begin(), B.end());

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += B[i];
    }
    int ave = round((float)sum / n);

    int center = B[n / 2];

    int frequency;
    if (A.size() > 1 && A[0].first > A[1].first) {
        frequency = A[0].second;
    } else if (A.size() == 1) {
        frequency = A[0].second;
    } else if (A.size() > 1 && A[0].first == A[1].first) {
        frequency = A[1].second;
    }

    int range = B[n - 1] - B[0];

    cout << ave << '\n' << center << '\n' << frequency << '\n' << range << '\n';
}
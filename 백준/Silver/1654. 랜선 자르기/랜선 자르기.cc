#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k, n;
    cin >> k >> n;
    vector<int> A;

    for (int i = 0; i < k; i++) {
        int len;
        cin >> len;

        A.push_back(len);
    }
    sort(A.begin(), A.end(), greater<int>());

    long long max = A[0];
    long long gasu_hap;

    long long min = 1;
    long long mid;

    while (min <= max) {
        mid = (max + min) / 2;
        if (mid == 0) mid = 1;

        gasu_hap = 0;

        for (int i = 0; i < A.size(); i++) {
            gasu_hap += A[i] / mid;
        }

        if (gasu_hap >= n) {
            min = mid + 1;
        } else {
            max = mid - 1;
        }
    }

    cout << max << '\n';
}
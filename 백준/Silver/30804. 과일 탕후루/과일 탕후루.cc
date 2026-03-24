#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int cnt[10] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int left = 0, max = 0, types = 0;

    for (int right = 0; right < n; right++) {
        if (cnt[A[right]] == 0) types++;
        cnt[A[right]]++;

        while (types > 2) {
            cnt[A[left]]--;
            if (cnt[A[left]] == 0) types--;
            left++;
        }

        int gasu = right - left + 1;
        if (gasu > max) max = gasu;
    }

    cout << max << '\n';
}
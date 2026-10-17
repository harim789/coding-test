#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 2; j < n; j++) {
            int hap = a[i] + a[j];
            res = max(res, hap);
        }
    }

    cout << res;

    return 0;
}
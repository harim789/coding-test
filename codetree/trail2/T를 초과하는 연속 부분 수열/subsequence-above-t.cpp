#include <iostream>
using namespace std;

int main() {
    int n, t;

    int x[1000];

    cin >> n >> t;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    int cnt = 0;
    int max = 0;

    if (x[0] > t) cnt = 1;

    for (int i = 1; i < n; i++) {
        if (x[i] <= t) {
            if (max < cnt) max = cnt;
            cnt = 0;
        } else {
            cnt++;
        }
    }

    if (max < cnt) max = cnt;

    cout << max;

    return 0;
}
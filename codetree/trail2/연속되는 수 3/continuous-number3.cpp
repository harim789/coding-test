#include <iostream>
using namespace std;

int main() {
    int n;

    int x[1000];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    int cnt = 0;
    int max = 0;

    for (int i = 0; i < n; i++) {
        if (i == 0 || (x[i] < 0 && x[i - 1] > 0) || (x[i] > 0 && x[i - 1] < 0)) {
            if (max < cnt) max = cnt;
            cnt = 1;
        } else {
            cnt++;
        }
    }

    if (max < cnt) max = cnt;

    cout << max;

    return 0;
}
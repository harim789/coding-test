#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int min = 1000000;
    for (int i = 0; i < n; i++) {
        int each_dist = 0;

        for (int j = 0; j < n; j++) {
            each_dist += abs(i - j) * a[j];
        }

        if (min > each_dist) min = each_dist;
    }

    cout << min;

    return 0;
}
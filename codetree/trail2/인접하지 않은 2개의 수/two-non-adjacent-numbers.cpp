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

    int max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < i - 1 || j > i + 1) {
                int hap = a[i] + a[j];
                if (max < hap) max = hap;
            }
        }
    }

    cout << max;

    return 0;
}
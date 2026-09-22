#include <iostream>
#include <vector>

using namespace std;

int n;
int x1[100], x2[100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }

    vector<int> v(200, 0);
    for (int i = 0; i < n; i++) {
        int start_idx = x1[i] + 100;
        int end_idx = x2[i] + 100;

        for (int j = start_idx; j < end_idx; j++) {
            v[j]++;
        }
    }

    int max = v[0];
    for (int i = 1; i < 200; i++) {
        if (max < v[i]) max = v[i];
    }

    cout << max;

    return 0;
}
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

    vector<int> v(101, 0);
    for (int i = 0; i < n; i++) {
        for (int j = x1[i]; j <= x2[i]; j++) {
            v[j]++;
        }
    }

    int max = v[0];
    for (int i = 1; i <= 100; i++) {
        if (max < v[i]) max = v[i];
    }

    cout << max;
    
    return 0;
}
// 4 7 8 6 4

// 1번: 
// 2번: 8 + 6*2 + 4*3 + 4*4 = 8 + 12 + 12 + 16 = 48

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int min = INT_MAX;
    for (int i = 0; i < n; i++) {
        int each_sum = 0;
        for (int j = 0; j < n; j++) {
            int apart;
            if (i > j) {
                apart = j + n - i;
            } else {
                apart = j - i;
            }

            each_sum += apart * v[j];
        }

        if (min > each_sum) min = each_sum;
    }
    
    cout << min;

    return 0;
}
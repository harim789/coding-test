#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

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

    vector<int> temp = A;
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    for (int i = 0; i < n; i++) {
        int min = 0;
        int max = temp.size() - 1;

        while (min <= max) {
            int mid = (min + max) / 2;

            if (temp[mid] < A[i]) {
                min = mid + 1;
            } else {
                max = mid - 1;
            }
        }

        cout << max + 1 << ' ';
    }
    cout << '\n';
}
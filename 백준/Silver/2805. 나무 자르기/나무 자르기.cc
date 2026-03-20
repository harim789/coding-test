#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> A;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        A.push_back(x);
    }
    sort(A.begin(), A.end(), greater<int>());

    long long min = 1;
    long long max = A[0];

    while (min <= max) {
        long long mid = (min + max) / 2;
        long long cut_sum = 0;

        for (int i = 0; i < n; i++) {
            if (A[i] > mid) {
                cut_sum += A[i] - mid;
            }
        }

        if (cut_sum >= m) {
			min = mid + 1;
        } else {
			max = mid - 1;
		}
    }

	cout << max << '\n';
}
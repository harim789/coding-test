#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    int count = 0;
    for (int i = 0; i < N; i++) {
        int find = A[i];
        int start_index = 0;
        int end_index = N - 1;

        while (start_index < end_index) {
            int sum = A[start_index] + A[end_index];
            if (sum == find) {
                if (start_index != i && end_index != i) {
                    count++;
                    break;
                } else if (start_index == i) {
                    start_index++;
                } else if (end_index == i) {
                    end_index--;
                }
            } else if (sum < A[i]) {
                start_index++;
            } else {
                end_index--;
            }
        }
    }

    cout << count << "\n";
}
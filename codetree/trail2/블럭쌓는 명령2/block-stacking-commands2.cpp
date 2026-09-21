#include <iostream>
#include <vector>

using namespace std;

int N, K;
int A[100], B[100];

int main() {
    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        cin >> A[i] >> B[i];
    }

    vector<int> v(N + 1, 0);

    for (int i = 0; i < K; i++) {
        for (int j = A[i]; j <= B[i]; j++) {
            v[j]++;
        }
    }

    int max = v[1];
    for (int i = 2; i <= N; i++) {
        if (max < v[i]) max = v[i];
    }

    cout << max;
    
    return 0;
}
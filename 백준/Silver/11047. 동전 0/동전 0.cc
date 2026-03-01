#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end(), greater<int>());

    int count;
    count = K / A[0];
    for (int i = 0; i < N - 1; i++) {
        count += (K % A[i]) / A[i + 1];
    }
	
	cout << count << '\n';
}
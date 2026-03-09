#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    queue<int> A;

    for (int i = 1; i <= n; i++) {
        A.push(i);
    }

    int start;
    vector<int> B;
    while(A.size()) {
        for (int i = 0; i < k - 1; i++) {
            int front = A.front();
            A.pop();
            A.push(front);
        }

        B.push_back(A.front());
        A.pop();
    }

    cout << '<';
    for (int i = 0; i < n - 1; i++) {
        cout << B[i] << ", ";
    }
	cout << B[n-1] << ">\n";
}
#include <iostream>
#include <stack>
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

    stack<int> index;
    vector<int> ans(N, 0);

    index.push(0);
    for (int i = 1; i < N; i++) {
        while (!index.empty() && A[index.top()] < A[i]) {
            int a = index.top();
            ans[a] = A[i];
            index.pop();
        }
        index.push(i);
    }

    while (!index.empty()) {
        ans[index.top()] = -1;
        index.pop();
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << ' ';
    }
    cout << "\n";
}
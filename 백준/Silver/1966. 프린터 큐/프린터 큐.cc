#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;

        queue<pair<int, bool>> myQueue;
        vector<int> A;
        for (int j = 0; j < n; j++) {
            int priority;
            cin >> priority;
            bool isM = false;

            if (j == m) {
                isM = true;
            }

            myQueue.push(make_pair(priority, isM));
            A.push_back(priority);
        }

        sort(A.begin(), A.end());

        int count = 1;

        while (1) {
            pair<int, bool> front = myQueue.front();
            if (front.first == A[A.size() - 1] && front.second) {
                cout << count << '\n';
                break;
            } else if (front.first == A[A.size() - 1] && !front.second) {
                myQueue.pop();
                A.pop_back();
                count++;
            } else {
                myQueue.pop();
                myQueue.push(front);
            }
        }
    }
}
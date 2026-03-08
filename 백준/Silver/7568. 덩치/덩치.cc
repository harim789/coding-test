#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> A(n);

    for (int i = 0; i < n; i++) {
		cin >> A[i].first >> A[i].second;
    }

    for (int i = 0; i < n; i++) {
        int bigger_cnt = 0;
        for (int j = 0; j < n; j++) {
            if (A[i].first < A[j].first && A[i].second < A[j].second) {
                bigger_cnt++;
            }
        }

		cout << bigger_cnt + 1 << ' ';
    }
	
    cout << '\n';
}
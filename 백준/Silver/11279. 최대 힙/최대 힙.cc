#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	priority_queue<int, vector<int>, less<int>> pq;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (x == 0) {
			if (pq.empty()) {
				cout << 0 << '\n';
			} else {
				int max = pq.top();
				cout << max << '\n';
				pq.pop();
			}
		} else {
			pq.push(x);
		}
	}
}
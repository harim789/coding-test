#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> order;
    vector<int> ans;

    for (int i = 0; i < N; i++) {
        int su;
        cin >> su;

        if (su != 0) {
            auto it = lower_bound(order.begin(), order.end(), su, [](int a, int b) {
                if (abs(a) != abs(b)) return abs(a) < abs(b);
                return a < b;
            });
           order.insert(it, su);
        } else {
			if (order.empty()) {
				ans.push_back(0);
			} else {
				ans.push_back(order[0]);
				order.erase(order.begin());
			}
		}
    }

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
}
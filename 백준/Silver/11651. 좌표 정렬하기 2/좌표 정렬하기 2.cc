#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> A(n);

	for (int i = 0; i < n; i++) {
		cin >> A[i].second >> A[i].first;
	}

	sort(A.begin(), A.end());

	for (int i = 0; i < n; i++) {
		cout << A[i].second << ' ' << A[i].first << '\n';
	}
}
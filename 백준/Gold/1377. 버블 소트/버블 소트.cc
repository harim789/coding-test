#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, int>> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i].second;
		A[i].first = i;
	}

	sort(A.begin(), A.end(), compare);

	int max = 0;
	for (int i = 0; i < N; i++) {
		if (max < A[i].first - i) {
			max = A[i].first - i;
		}
	}

	cout << max + 1 << "\n";
}
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++) {
        int s, e;
        cin >> s >> e;
        A[i] = make_pair(e, s);
    }

	// end가 작은 순으로 정렬
    sort(A.begin(), A.end());

	// first : end, second: start
	int count = 1;
	int current_end = A[0].first;

	for (int i = 1; i < N; i++) {
		if (current_end <= A[i].second) {
			count++;
			current_end = A[i].first;
		}
	}

	cout << count << '\n';
}
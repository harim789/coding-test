#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int> A(N, 0);
	
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());

	int start_index = 0;
	int end_index = N-1;
	int count = 0;

	while (start_index < end_index) {
		int sum = A[start_index] + A[end_index];

		if (sum < M) {
			start_index++;
		} else if (sum == M) {
			count++;
			start_index++;
			end_index--;
		} else {
			end_index--;
		}
	}

	cout << count << "\n";
}
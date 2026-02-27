#include <iostream>
#include <vector>
#include <algorithm>
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
	sort(A.begin(), A.end());

	int find_num;
	cin >> find_num;

	for (int i = 0; i < find_num; i++) {
		bool find = false;
		int target;
		cin >> target;

		int start = 0;
		int end = N - 1;

		while (start <= end) {
			int mid_index = (start + end) / 2;
			int mid_num = A[mid_index];

			if (target == mid_num) {
				find = true;
				break;
			} else if (target < mid_num) {
				end = mid_index - 1;
			} else {
				start = mid_index + 1;
			}
		}

		if (find) {
			cout << 1 << '\n';
		} else {
			cout << 0 << '\n';
		}
	}
}
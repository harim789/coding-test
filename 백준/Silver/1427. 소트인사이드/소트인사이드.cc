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

	string str_num = to_string(N);
	int len = str_num.length();

	vector<int> A(len);

	for (int i = 0; i < len; i++) {
		A[i] = str_num[i] - '0';
	}

	sort(A.begin(), A.end(), greater<int>());

	for (int i = 0; i < len; i++) {
		cout << A[i];
	}
}
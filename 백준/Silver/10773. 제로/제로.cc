#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k;
	cin >> k;
	stack<int> A;

	for (int i = 0; i < k; i++) {
		int n;
		cin >> n;
		if (n != 0) {
			A.push(n);
		} else {
			A.pop();
		}
	}

	int sum = 0;
	while (A.size()) {
		sum += A.top();
		A.pop();
	}

	cout << sum << '\n';
}


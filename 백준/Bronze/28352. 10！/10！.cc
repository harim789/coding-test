#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	long long res = 6;
	for (int i = 11; i <= n; i++) {
		res *= i;
	}

	cout << res << '\n';
}
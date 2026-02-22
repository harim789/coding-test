#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	int count[10001] = {0};
	for (int i = 0; i < N; i++) {
		int su;
		cin >> su;
		count[su]++;
	}

	for (int i = 1; i <= 10000; i++) {
		while (count[i]--) {
			cout << i << "\n";
		}
	}
}
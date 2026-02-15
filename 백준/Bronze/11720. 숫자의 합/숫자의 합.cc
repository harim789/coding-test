#include <iostream>
using namespace std;

int main() {
	int N = 0;
	string s;

	cin >> N;
	cin >> s;

	int length = s.length();
	int sum = 0;
	for (int i = 0; i < length; i++) {
		sum += s[i] - '0';
	}

	cout << sum << "\n";

	return 0;
}
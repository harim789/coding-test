#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int b;
	cin >> b;

	b /= 11;
	b *= 10;

	cout << b << '\n';
}
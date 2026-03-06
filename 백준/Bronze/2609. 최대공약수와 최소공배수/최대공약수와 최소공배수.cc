#include <iostream>
using namespace std;

int gcd(int a, int b);

int main() {
	int a, b;
	cin >> a >> b;

	int gcd_su = gcd(a, b);
	int lcm_su = a * b / gcd_su;

	cout << gcd_su << '\n';
	cout << lcm_su << '\n';
}

int gcd(int a, int b) {
	if (a % b == 0) {
		return b;
	} else {
		return gcd(b, a % b);
	}
}
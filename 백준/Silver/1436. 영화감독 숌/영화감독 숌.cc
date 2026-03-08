#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int su = 666;
	int count = 1;
	while (n != count) {
		su++;
		string str = to_string(su);
		if (str.find("666") != -1) count++;
	}

	cout << su << '\n';
}
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(int a);

int main() {
	while (1) {
		int num;
		cin >> num;

		if (num == 0) break;

		if (isPalindrome(num)) {
			cout << "yes" << '\n';
		} else {
			cout << "no" << '\n';
		}
	}
}

bool isPalindrome(int a) {
	string str = to_string(a);
	
	for (int i = 0; i < str.length()/2; i++) {
		if (str[i] != str[str.length()-i-1]) {
			return false;
		}
	}

	return true;
}
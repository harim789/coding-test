#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	stack<char> A;
	for (int i = 0; i < t; i++) {
		string str;
		cin >> str;

		int len = str.length();
		bool isAnswered = false;
		for (int j = 0; j < len; j++) {
			if (str[j] == '(') {
				A.push('(');
			} else if (str[j] == ')') {
				if (A.size() && A.top() == '(') {
					A.pop();
				} else {
					cout << "NO" << '\n';
					isAnswered = true;
					break;
				}
			}
		}

		if (!isAnswered && !A.size()) {
			cout << "YES" << '\n';
		} else if (!isAnswered && A.size()) {
			cout << "NO" << '\n';
		}

		while (A.size()) {
			A.pop();
		}
	}
}
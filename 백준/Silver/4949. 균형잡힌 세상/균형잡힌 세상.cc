#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<char> brackets;

    while (1) {
        string str;
        getline(cin, str);

        if (str == ".") break;

        int len = str.length();
        bool isAnswered = false;

        for (int i = 0; i < len; i++) {
            if (str[i] == '(' || str[i] == '[') {
                brackets.push(str[i]);
            }

            if (str[i] == ')') {
                if (brackets.size() && brackets.top() == '(') {
                    brackets.pop();
                } else {
                    cout << "no" << '\n';
                    isAnswered = true;
                    break;
                }
            } else if (str[i] == ']') {
                if (brackets.size() && brackets.top() == '[') {
                    brackets.pop();
                } else {
                    cout << "no" << '\n';
                    isAnswered = true;
                    break;
                }
            }
        }

        if (!isAnswered && brackets.size()) {
            cout << "no" << '\n';
        } else if (!isAnswered && !brackets.size()) {
            cout << "yes" << '\n';
        }
		
		while (brackets.size()) {
			brackets.pop();
		}
    }
}
#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    stack<int> A;

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command == "push") {
            int push_num;
            cin >> push_num;
			A.push(push_num);
        } else if (command == "pop") {
			if (A.size()) {
				cout << A.top() << '\n';
				A.pop();
			} else {
				cout << -1 << '\n';
			}
		} else if (command == "size") {
			cout << A.size() << '\n';
		} else if (command == "empty") {
			if (A.empty()) {
				cout << 1 << '\n';
			} else {
				cout << 0 << '\n';
			}
		} else if (command == "top") {
			if (!A.empty()) {
				cout << A.top() << '\n';
			} else {
				cout << -1 << '\n';
			}
		}
    }
}
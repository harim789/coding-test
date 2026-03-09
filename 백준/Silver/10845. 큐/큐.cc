#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    queue<int> A;

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command == "push") {
            int push_num;
            cin >> push_num;

            A.push(push_num);
        } else if (command == "pop") {
			if (!A.empty()) {
				cout << A.front() << '\n';
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
        } else if (command == "front") {
			if (!A.empty()) {
				cout << A.front() << '\n';
			} else {
				cout << -1 << '\n';
			}
        } else if (command == "back") {
			if (!A.empty()) {
				cout << A.back() << '\n';
			} else {
				cout << -1 << '\n';
			}
        }
    }
}
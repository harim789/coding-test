#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;
    cin >> m;
    vector<bool> exist(21, false);

    for (int i = 0; i < m; i++) {
        string command;
        cin >> command;

        if (command == "add") {
            int x;
            cin >> x;
            if (!exist[x]) exist[x] = true;
        } else if (command == "remove") {
            int x;
            cin >> x;
            if (exist[x]) exist[x] = false;
        } else if (command == "check") {
            int x;
            cin >> x;
            if (exist[x]) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        } else if (command == "toggle") {
            int x;
            cin >> x;
            if (exist[x]) {
                exist[x] = false;
            } else {
                exist[x] = true;
            }
        } else if (command == "all") {
            for (int i = 1; i <= 20; i++) {
                exist[i] = true;
            }
        } else if (command == "empty") {
            for (int i = 1; i <= 20; i++) {
                exist[i] = false;
            }
        }
    }
}
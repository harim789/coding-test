#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    map<string, string> password;

    for (int i = 0; i < n; i++) {
        string addr, passwd;
        cin >> addr >> passwd;

        password[addr] = passwd;
    }

    for (int i = 0; i < m; i++) {
        string find;
        cin >> find;

		cout << password[find] << '\n';
    }
}
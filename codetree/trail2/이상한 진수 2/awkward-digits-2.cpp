#include <iostream>
using namespace std;

int main() {
    string a;
    cin >> a;

    bool exist_zero = false;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '0') {
            exist_zero = true;
            a[i] = '1';
            break;
        }
    }

    if (!exist_zero) {
        a[a.size() - 1] = '0';
    }

    int res = 0;
    int jegop = 1;
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] == '1') {
            res += jegop;
        }
        jegop *= 2;
    }

    cout << res;

    return 0;
}
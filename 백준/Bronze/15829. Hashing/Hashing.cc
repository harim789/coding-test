#include <iostream>
using namespace std;

int main() {
    int m = 1234567891;

    int l;
    cin >> l;

    string str;
    cin >> str;

    int sum = 0;
    long r = 1;
    for (int i = 0; i < l; i++) {
        int a = str[i] - 'a' + 1;
        sum = (sum + (a * r)) % m;

        r = (r * 31) % m;
    }

    cout << sum << '\n';
}
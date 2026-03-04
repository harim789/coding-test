#include <iostream>
using namespace std;

long gcd(long a, long b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long A, B;
    cin >> A >> B;

    long gcd_su = gcd(A, B);

    for (long i = 0; i < gcd_su; i++) {
        cout << 1;
    }

    cout << '\n';
}

long gcd(long a, long b) {
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}
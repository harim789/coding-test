#include <iostream>
using namespace std;

int gcd(int a, int b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int A, B;
        cin >> A >> B;

        int result = A * B / gcd(A, B);
        cout << result << '\n';
    }
}

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}
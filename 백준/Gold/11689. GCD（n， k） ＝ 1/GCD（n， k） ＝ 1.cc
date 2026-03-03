#include <cmath>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long n;
    cin >> n;
    long result = n;
	long fix_n = n;

    for (long p = 2; p <= sqrt(fix_n); p++) {
        if (n % p == 0) {
            result = result - result / p;

            while (n % p == 0) {
                n /= p;
            }
        }
    }

    if (n > 1) {
        result = result - result / n;
    }

    cout << result << '\n';
}
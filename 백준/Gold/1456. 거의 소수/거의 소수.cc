#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long A, B;
    cin >> A >> B;
    vector<int> C(sqrt(B) + 1);

    for (int i = 2; i <= sqrt(B); i++) {
        C[i] = i;
    }

    for (int i = 2; i <= sqrt(B); i++) {
        if (C[i] == 0) {
            continue;
        }
        for (int j = i + i; j <= sqrt(B); j += i) {
            C[j] = 0;
        }
    }

    long long count = 0;
    for (long long i = 2; i <= sqrt(B); i++) {
        if (C[i] != 0) {
            long long a = (long long)C[i] * C[i];
            while (a <= B) {
                if (a >= A) {
                    count++;
                }
				if (C[i] > B / a) break; 
                a *= C[i];
            }
        }
    }

    cout << count << '\n';
}
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int A, B;
        cin >> A >> B;

        int bigger = A;
        int smaller = B;
        if (A < B) {
            bigger = B;
			smaller = A;
        }

		while (bigger % smaller != 0) {
			int temp = smaller;
			smaller = bigger % smaller;
			bigger = temp;
		}
		int GCD = smaller;

		int LCM;
		if (GCD == 1) {
			LCM = A * B;
		} else {
			LCM = A * B / GCD;
		}

		cout << LCM << '\n';
    }
}
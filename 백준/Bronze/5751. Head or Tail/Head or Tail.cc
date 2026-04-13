#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {
        int n;
        cin >> n;

        if (n == 0) break;

        int zero = 0;
        int one = 0;
        for (int i = 0; i < n; i++) {
            int r;
            cin >> r;

            if (r == 0) {
                zero++;
            } else {
				one++;
			}
        }

		cout << "Mary won " << zero << " times and John won " << one << " times\n";
    }
}
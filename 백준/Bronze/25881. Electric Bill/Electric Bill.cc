#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r_1000, r_extra;
    cin >> r_1000 >> r_extra;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;

        int res;
        if (e <= 1000) {
            res = r_1000 * e;
        } else {
            res = r_1000 * 1000;
            res += r_extra * (e - 1000);
        }

		cout << e << ' ' << res << '\n';
    }
}
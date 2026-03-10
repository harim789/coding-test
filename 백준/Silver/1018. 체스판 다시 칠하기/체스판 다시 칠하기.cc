#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<string> A(n);

    for (int i = 0; i < n; i++) cin >> A[i];

    int min_repaint = 64;
    for (int i = 0; i <= n - 8; i++) {
        for (int j = 0; j <= m - 8; j++) {
            int countW = 0;

            for (int x = i; x < i + 8; x++) {
                for (int y = j; y < j + 8; y++) {
                    if ((x + y) % 2 == 0) {
                        if (A[x][y] != 'W') countW++;
                    } else {
                        if (A[x][y] != 'B') countW++;
                    }
                }
            }

            int smaller = min(countW, 64 - countW);
			if (smaller < min_repaint) min_repaint = smaller;
        }
    }

    cout << min_repaint << '\n';
}
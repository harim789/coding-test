#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    char A[n][m];

    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++) {
            A[i][j] = line[j];
        }
    }

    int min = 64;
    for (int i = 0; i <= n - 8; i++) {
        for (int j = 0; j <= m - 8; j++) {
            int repaint_1 = 0;
			int repaint_2 = 0;

            for (int x = i; x < i + 8; x++) {
                for (int y = j; y < j + 8; y++) {
                    if ((x % 2 == i % 2 && y % 2 == j % 2) || (x % 2 != i % 2 && y % 2 != j % 2)) {
                        if (A[x][y] != A[i][j]) {
                            repaint_1++;
                        } else {
							repaint_2++;
						}
                    } else {
                        if (A[x][y] == A[i][j]) {
                            repaint_1++;
                        } else {
							repaint_2++;
						}
                    }
                }
            }

			int smaller = repaint_1;
			if (repaint_1 > repaint_2) {
				smaller = repaint_2;
			}
            if (smaller < min) min = smaller;
        }
    }

    cout << min << '\n';
}
#include <iostream>
using namespace std;

int A[51][51];
int n, m;
void clear(int a, int b);
void dfs(int a, int b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int k;
        cin >> m >> n >> k;

        clear(m, n);
        int gasu = 0;

        for (int j = 0; j < k; j++) {
            int x, y;
            cin >> x >> y;

            A[x][y] = 1;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] == 1) {
                    gasu++;
                    dfs(i, j);
                }
            }
        }

        cout << gasu << '\n';
    }
}

void clear(int a, int b) {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            A[i][j] = 0;
        }
    }
}

void dfs(int a, int b) {
    if (a < 0 || b < 0 || a >= m || b >= n || A[a][b] == 0) return;

    A[a][b] = 0;

    dfs(a - 1, b);
    dfs(a + 1, b);
    dfs(a, b - 1);
    dfs(a, b + 1);
}
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    string str;
    cin >> str;

    int res = 0;
    for (int left = 0; left < m - 1; left++) {
        int i = left;
        if (str[i] == 'I' && str[i + 1] == 'O' && str[i + 2] == 'I') {
            int patternCnt = 0;

            while (str[i + 1] == 'O' && str[i + 2] == 'I') {
                patternCnt++;

                if (patternCnt == n) {
                    res++;
                }
                i += 2;
            }
        }
    }

    cout << res << '\n';
}
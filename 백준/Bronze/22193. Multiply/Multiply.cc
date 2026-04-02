#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    string a, b;
    cin >> n >> m >> a >> b;

    vector<int> result(n + m, 0);

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[i + j] += (a[i] - '0') * (b[j] - '0');
        }
    }

    for (int i = 0; i < n + m - 1; i++) {
        result[i + 1] += result[i] / 10;
        result[i] %= 10;
    }

    int start = n + m - 1;
    while (start > 0 && result[start] == 0) start--;
    
    for (int i = start; i >= 0; i--) {
        cout << result[i];
    }
    cout << '\n';

    return 0;
}

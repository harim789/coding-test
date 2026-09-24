#include <iostream>
using namespace std;

int main() {
    int n, m, k;

    int x[10000];

    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        cin >> x[i];
    }

    int bulchic[n + 1] = {0};
    bool exist = false;
    for (int i = 0; i < m; i++) {
        bulchic[x[i]]++;

        if (bulchic[x[i]] == k) {
            exist = true;
            cout << x[i];
            break;
        }
    }

    if (!exist) {
        cout << -1;
    }

    return 0;

}
#include <iostream>
using namespace std;

int main() {
    int test_num;
    cin >> test_num;

    for (int i = 0; i < test_num; i++) {
        int k, n;
        cin >> k >> n;

        int apt[15][15] = {0};
        for (int i = 1; i <= 14; i++) {
            apt[0][i] = i;
        }

        for (int j = 1; j <= k; j++) {
            for (int l = 1; l <= n; l++) {
                for (int z = 1; z <= l; z++) {
                    apt[j][l] += apt[j - 1][z];
                }
                // cout << "apt[" << j << "][" << l << "] = " << apt[j][l] << '\n';
            }
        }

        cout << apt[k][n] << '\n';
    }
}
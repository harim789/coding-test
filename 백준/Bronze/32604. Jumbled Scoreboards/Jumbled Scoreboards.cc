#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    bool isChronological = true;
    int cur_a, cur_b;
    cin >> cur_a >> cur_b;

    for (int i = 0; i < n - 1; i++) {
        int next_a, next_b;
        cin >> next_a >> next_b;

        if (next_a < cur_a || next_b < cur_b) {
            isChronological = false;
        }

        cur_a = next_a;
        cur_b = next_b;
    }

    if (isChronological) {
        cout << "yes" << '\n';
    } else {
        cout << "no" << '\n';
    }
}
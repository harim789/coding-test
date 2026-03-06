#include <iostream>
using namespace std;

int main() {
    string lsbn;
    cin >> lsbn;

    int sub_sum = 0;
    int asterisk_index;
    for (int i = 0; i < 13; i++) {
        if (lsbn[i] == '*') {
            asterisk_index = i;
            continue;
        }

        // 홀수 => X1, 짝수 => X3
        int su = lsbn[i] - '0';
        if (i % 2 == 0) {
            sub_sum = (sub_sum + su) % 10;
        } else {
            sub_sum = (sub_sum + su * 3) % 10;
        }
        // cout << sub_sum << ' ';
    }

    for (int i = 0; i < 10; i++) {
        if (asterisk_index % 2 == 0) {
            if ((i + sub_sum) % 10 == 0) {
                cout << i << '\n';
                break;
            }
        } else {
            if ((3 * i + sub_sum) % 10 == 0) {
                cout << i << '\n';
                break;
            }
        }
    }
}
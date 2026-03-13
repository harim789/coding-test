#include <iostream>
using namespace std;

int A[128][128];
int count_white;
int count_blue;
void gasu(int x, int y, int size);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    gasu(0, 0, n);

    cout << count_white << '\n';
    cout << count_blue << '\n';
}

void gasu(int x, int y, int size) {
    int standard = A[x][y];

    bool isSameColor = true;
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (A[i][j] != standard) {
                isSameColor = false;
                break;
            }
        }
		if (!isSameColor) break;
    }

    if (isSameColor) {
        if (standard == 0) {
            count_white++;
        }

        if (standard == 1) {
            count_blue++;
        }
    } else if (!isSameColor) {
		int half = size / 2;
        gasu(x, y, half);
        gasu(x + half, y, half);
        gasu(x, y + half, half);
        gasu(x + half, y + half, half);
    }
}
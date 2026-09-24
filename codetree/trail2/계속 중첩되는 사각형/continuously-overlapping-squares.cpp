#include <iostream>

using namespace std;

#define red 1
#define blue 2

int main() {
    int n;

    int x1[10], y1[10];
    int x2[10], y2[10];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }

    int checked[200][200];

    for (int i = 0; i < n; i++) {
        int color;

        if (i % 2 == 0) {
            color = red;
        } else {
            color = blue;
        }

        for (int j = x1[i]; j < x2[i]; j++) {
            for (int k = y1[i]; k < y2[i]; k++) {
                checked[j + 100][k + 100] = color;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            if (checked[i][j] == blue) cnt++; 
        }
    }

    cout << cnt;

    return 0;
}
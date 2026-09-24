#include <iostream>
using namespace std;

int main() {
    int x1[2], y1[2];
    int x2[2], y2[2];

    cin >> x1[0] >> y1[0] >> x2[0] >> y2[0];
    cin >> x1[1] >> y1[1] >> x2[1] >> y2[1];

    int checked[2000][2000];

    for (int i = x1[0]; i < x2[0]; i++) {
        for (int j = y1[0]; j < y2[0]; j++) {
            checked[i + 1000][j + 1000] = 1;
        }
    }

    for (int i = x1[1]; i < x2[1]; i++) {
        for (int j = y1[1]; j < y2[1]; j++) {
            if (checked[i + 1000][j + 1000] == 1) {
                checked[i + 1000][j + 1000] = 0;
            }
        }
    }

    int min_x = x2[0];
    int max_x = x1[0];
    int min_y = y2[0];
    int max_y = y1[0];

    bool residue = false;
    for (int i = x1[0]; i < x2[0]; i++) {
        for (int j = y1[0]; j < y2[0]; j++) {
            if (checked[i + 1000][j + 1000] == 1) {
                residue = true;

                if (min_x > i) min_x = i;
                if (max_x < i) max_x = i;
                if (min_y > j) min_y = j;
                if (max_y < j) max_y = j;
            }
        }
    }

//    cout << "max_x = " << max_x << endl;
//    cout << "min_x = " << min_x << endl;
//    cout << "max_y = " << max_y << endl;
//    cout << "min_y = " << min_y << endl;

    if (residue) {
        int area = (max_x - min_x + 1) * (max_y - min_y + 1);
        cout << area;
    } else {
        cout << 0;
    }

    return 0;
}
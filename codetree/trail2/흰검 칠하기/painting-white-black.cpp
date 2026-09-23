#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    int x[1000];
    char dir[1000];

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> dir[i];
    }

    vector<int> black(200001, 0);
    vector<int> white(200001, 0);
    vector<char> color(200001, 'n');

    int cur = 100000;
    for (int i = 0; i < n; i++) {
        if (dir[i] == 'L') {
            white[cur]++;
            color[cur] = 'w';

            for (int j = 1; j < x[i]; j++) {
                white[cur - j]++;
                color[cur - j] = 'w';
            }

            cur -= (x[i] - 1);
        } else {
            black[cur]++;
            color[cur] = 'b';

            for (int j = 1; j < x[i]; j++) {
                black[cur + j]++;
                color[cur + j] = 'b';
            }

            cur += (x[i] - 1);
        }
    }
    
    int white_su = 0;
    int black_su = 0;
    int gray_su = 0;

    for (int i = 0; i < 200001; i++) {
        if (white[i] >= 2 && black[i] >= 2) {
            gray_su++;
        } else {
            if (color[i] == 'w') {
                white_su++;
            } else if (color[i] == 'b') {
                black_su++;
            }
        }
    }

    cout << white_su << ' ' << black_su << ' ' << gray_su;

    return 0;
}
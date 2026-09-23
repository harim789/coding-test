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

    vector<char> color(200001, 'n');

    int cur = 100000;

    for (int i = 0; i < n; i++) {
        if (dir[i] == 'L') {
            color[cur] = 'w';

            for (int j = 1; j < x[i]; j++) {
                color[cur - j] = 'w';
            }

            cur -= (x[i] - 1);
        } else {
            color[cur] = 'b';

            for (int j = 1; j < x[i]; j++) {
                color[cur + j] = 'b';
            }

            cur += (x[i] - 1);
        }
    }

    int white = 0;
    int black = 0;

    for (int i = 0; i < 200000; i++) {
        if (color[i] == 'w') {
            white++;
        } else if (color[i] == 'b') {
            black++;
        }
    }

    cout << white << ' ' << black;
}
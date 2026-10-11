// tolower, toupper 알아두기!
// 하지만 여기에서는 안 써도 되는 거였음

// cout << tolower('A'); 는 97이고, 
// 
// char a  = tolower('A');
// cout << a; 는 a로 출력된다.

#include <iostream>
#include <vector>
using namespace std;

int dir_r[4] = {0, 1, 0, -1};
int dir_c[4] = {1, 0, -1, 0};

int n, m;

bool inRange(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < m);
}

int main() {
    cin >> n >> m;

    vector<vector<char>> mat(n);
    for (int i = 0; i < n; i++) {
        mat[i].resize(m, 'n');
    }

    int cur_dir = 0;
    char cur_alphabet = 'A';
    int cur_r = 0;
    int cur_c = 0;

    mat[cur_r][cur_c] = cur_alphabet;
    for (int i = 0; i < n * m - 1; i++) {
        if (cur_alphabet == 'Z') {
            cur_alphabet = 'A';
        } else {
            cur_alphabet++;
        }

        int next_r = cur_r + dir_r[cur_dir];
        int next_c = cur_c + dir_c[cur_dir];

        if (!inRange(next_r, next_c) || mat[next_r][next_c] != 'n') {
            cur_dir = (cur_dir + 1) % 4;
            next_r = cur_r + dir_r[cur_dir];
            next_c = cur_c + dir_c[cur_dir];
        }

        mat[next_r][next_c] = cur_alphabet;
        cur_r = next_r;
        cur_c = next_c;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }
    
    return 0;
}
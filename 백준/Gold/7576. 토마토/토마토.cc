#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int m, n;
int a[1000][1000];
queue<pair<int, int>> q;
int cnt = 0;
void bfs();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            cin >> a[r][c];
            if (a[r][c] == 1) {
                q.push(make_pair(r, c));
            }

            // cout << "a[" << i << "][" << j << "] = " << a[i][j] << '\n';
        }
    }

    bfs();

    bool isRipe = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                isRipe = false;
				break;
            }
        }
    }

    if (isRipe) {
        cout << cnt << '\n';
    } else {
        cout << -1 << '\n';
    }
}

void bfs() {
    int dir_r[] = {-1, 0, 1, 0};
    int dir_c[] = {0, -1, 0, 1};

    while (!q.empty()) {
        int size = q.size();
        bool isExist = false;

        for (int i = 0; i < size; i++) {
            int cur_r = q.front().first;
            int cur_c = q.front().second;
            q.pop();

            for (int j = 0; j < 4; j++) {
                int next_r = cur_r + dir_r[j];
                int next_c = cur_c + dir_c[j];

                if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < m && a[next_r][next_c] == 0) {
                    // cout << "cnt: " << cnt << ", " << "a[" << next_x << "][" << next_y << "] = " << a[next_x][next_y] << '\n';
                    isExist = true;
                    a[next_r][next_c] = 1;
                    q.push(make_pair(next_r, next_c));
                }
            }
        }

        if (isExist) cnt++;
    }
}
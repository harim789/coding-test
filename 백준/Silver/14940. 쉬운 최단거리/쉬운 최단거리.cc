#include <iostream>
#include <queue>
using namespace std;

int n, m;
int a[1000][1000];
int res[1000][1000];
bool visited[1000][1000];
void bfs(int x, int y);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int start_x, start_y;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2) {
                start_x = i;
                start_y = j;
            }
        }
    }

    bfs(start_x, start_y);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
}

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

    int next_x, next_y;
    res[x][y] = 0;
	visited[x][y] = true;

    int dir_x[] = {-1, 0, 1, 0};
    int dir_y[] = {0, -1, 0, 1};

    while (!q.empty()) {
		int front_x = q.front().first;
		int front_y = q.front().second;
		q.pop();

        for (int i = 0; i < 4; i++) {
            next_x = front_x + dir_x[i];
            next_y = front_y + dir_y[i];

            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m) {
                if (a[next_x][next_y] == 1 && !visited[next_x][next_y]) {
                    res[next_x][next_y] = res[front_x][front_y] + 1;
					q.push(make_pair(next_x, next_y));
					visited[next_x][next_y] = true;
                }
            }
        }
    }

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && a[i][j] == 1) res[i][j] = -1;
		}
	}
}
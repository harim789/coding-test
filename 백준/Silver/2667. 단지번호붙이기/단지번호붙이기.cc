#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int house = 0;
int map[25][25];
void dfs(int x, int y);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    string s_row;
    for (int i = 0; i < n; i++) {
        cin >> s_row;

        for (int j = 0; j < n; j++) {
            map[i][j] = s_row[j] - '0';
        }
    }

	int danzi = 0;
	vector<int> res;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1) {
				danzi++;
                dfs(i, j);
				res.push_back(house);
				house = 0;
            }
        }
    }
	sort(res.begin(), res.end());

	cout << danzi << '\n';
	for (int i = 0; i < danzi; i++) {
		cout << res[i] << '\n';
	}
}

void dfs(int x, int y) {
    if (map[x][y] == 0 || map[x][y] == -1) return;

    house++;
    map[x][y] = -1;

    int dir_x[] = {-1, 0, 1, 0};
    int dir_y[] = {0, -1, 0, 1};

    for (int i = 0; i < 4; i++) {
        int next_x = x + dir_x[i];
        int next_y = y + dir_y[i];
        if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n) {
            dfs(next_x, next_y);
        }
    }
}
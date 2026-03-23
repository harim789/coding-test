#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> visited;
vector<string> A;
int n, m;
int cnt = 0;
void dfs(int x, int y);

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n >> m;

	visited.resize(n, vector<bool>(m, false));
	int x, y;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        A.push_back(str);

		for (int j = 0; j < m; j++) {
			if (str[j] == 'I') {
				x = i;
				y = j;
			}
		}
    }

	dfs(x, y);

	if (cnt == 0) {
		cout << "TT" << '\n';
	} else {
		cout << cnt << '\n';
	}
}

void dfs(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y] || A[x][y] == 'X') {
		return;
	}

	visited[x][y] = true;
	if (A[x][y] == 'P') cnt++;

	for (int i = 0; i < 4; i++) {
		dfs(x + dx[i], y + dy[i]);
	}
}
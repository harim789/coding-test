#include <iostream>
#include <queue>
using namespace std;

static int m[101][101];
static bool visited[101][101];
static int N, M;
void BFS(int i, int j);
static int dx[4] = {0, 1, 0, -1};
static int dy[4] = {1, 0, -1, 0};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string str_row;
		cin >> str_row;
		for (int j = 0; j < M; j++) {
			m[i][j] = str_row[j] - '0';
		}
	}

	BFS(0, 0);

	cout << m[N-1][M-1] << '\n';
}

void BFS(int i, int j) {
	queue<pair<int, int>> myQueue;
	// push 함수는 인자를 딱 하나만 받을 수 있으므로
	// pair<int, int>라는 하나의 객체를 만들어서 넣어줘야 함!
	// myQueue.push({x, y});도 가능! (C++ 11 이상)
	myQueue.push(make_pair(i, j));
	visited[i][j] = true;

	while (!myQueue.empty()) {
		int now[2];
		now[0] = myQueue.front().first;
		now[1] = myQueue.front().second;
		myQueue.pop();

		for (int k = 0; k < 4; k++) {
			int x = now[0] + dx[k];
			int y = now[1] + dy[k];

			if (x >= 0 && y >= 0 && x < N && y < M) {
				if (m[x][y] == 1 && !visited[x][y]) {
					visited[x][y] = true;
					m[x][y] = m[now[0]][now[1]] + 1;
					myQueue.push(make_pair(x, y));
				}
			}
		}
	}
}
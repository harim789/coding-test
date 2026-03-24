#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int k;
int dist[100001];
void bfs(int a);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n >> k;

	for (int i = 0; i < 100001; i++) {
		dist[i] = -1;
	}

    if (n > k) {
        cout << n - k << '\n';
    } else {
        bfs(n);
    }
}

void bfs(int a) {
    queue<int> q;
    q.push(a);
    dist[a] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == k) {
            cout << dist[cur] << '\n';
            return;
        }

        int next_pos[] = {cur - 1, cur + 1, cur * 2};

        for (int next : next_pos) {
            if (next >= 0 && next <= 100000 && dist[next] == -1) {
                q.push(next);
                dist[next] = dist[cur] + 1;
            }
        }
    }
}
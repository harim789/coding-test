#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> v;
int dist[101];
void bfs(int a);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    v.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    int min = 5000;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[j] = -1;
        }
        bfs(i);

        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            cnt += dist[j];
        }

        a[i] = cnt;
        if (cnt < min) min = cnt;
    }

    for (int i = 1; i <= n; i++) {
        if (min == a[i]) {
            cout << i << '\n';
            break;
        }
    }
}

void bfs(int a) {
    queue<int> q;
    q.push(a);
    dist[a] = 0;

    while (!q.empty()) {
        int f = q.front();
        q.pop();

        for (int i : v[f]) {
            if (dist[i] == -1) {
                dist[i] = dist[f] + 1;
                q.push(i);
            }
        }
    }
}
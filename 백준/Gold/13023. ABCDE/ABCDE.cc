#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;
void DFS(int v, int count);
static bool found = false;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    A.resize(N);
    visited = vector<bool>(N, false);

    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;

        A[s].push_back(e);
        A[e].push_back(s);
    }

    for (int i = 0; i < N; i++) {
        DFS(i, 1);
        if (found) break;
    }

    if (found) {
        cout << 1 << "\n";
    } else {
        cout << 0 << "\n";
    }
}

void DFS(int v, int count) {
    if (count >= 5) {
        found = true;
        return;
    }

    visited[v] = true;

    for (int i : A[v]) {
        if (visited[i]) {
            continue;
        }
        DFS(i, count + 1);
    }

    // 이 정점을 거쳐가는 모든 길을 다 확인했으니, 이제 다른 경로가 나를 쓸 수 있게 풀어줌
    visited[v] = false;
}
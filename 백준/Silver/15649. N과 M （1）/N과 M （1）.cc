#include <iostream>
#include <vector>
using namespace std;

static int N, M;
static vector<vector<int>> A;
static vector<bool> visited;
static vector<vector<int>> result;
void DFS(int v, int depth);
static int result_index;
static vector<int> each_result;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    A.resize(N + 1);
    visited = vector<bool>(N + 1, false);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i != j) {
                A[i].push_back(j);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        DFS(i, 1);
    }

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < M; j++) {
			cout << result[i][j] << ' ';
        }
        cout << "\n";
    }
}

void DFS(int v, int depth) {
    if (visited[v]) {
        return;
    }

    visited[v] = true;
    each_result.push_back(v);

    if (depth == M) {
        result.push_back(each_result);
    } else {
        for (int i : A[v]) {
            if (!visited[i]) {
                DFS(i, depth + 1);
            }
        }
    }

	each_result.pop_back();
    visited[v] = false;
}
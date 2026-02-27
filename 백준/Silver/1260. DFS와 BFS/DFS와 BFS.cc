#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

static vector<bool> visited;
static vector<vector<int>> A;
static queue<int> B;
static int N, M, V;
void DFS(int v);
void BFS(int v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> V;

    // DFS
    A.resize(N + 1);
    visited = vector<bool>(N + 1, false);

    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;

        A[s].push_back(e);
        A[e].push_back(s);
    }

    for (int i = 1; i <= N; i++) {
        sort(A[i].begin(), A[i].end());
    }

    DFS(V);
    cout << '\n';

    // BFS
	B = queue<int>();
    fill(visited.begin(), visited.end(), false);
	BFS(V);
	cout << '\n';
}

void DFS(int v) {
    if (visited[v]) return;

    cout << v << ' ';
    visited[v] = true;

    for (int i : A[v]) {
        if (!visited[i]) {
            DFS(i);
        }
    }
}

void BFS(int v) {
	// v queue에 삽입
	// v visited true로 만들기
	B.push(v);
	visited[v] = true;

	// <반복문> - 조건: 만약 큐에 아무것도 없다면 종료
	// v pop 하면서 cout => B[v]에 속하는 수들 push, visited = true
	while (B.size()) {
		int pop_num = B.front();
		B.pop();
		cout << pop_num << ' ';
		for (int i: A[pop_num]) {
			if (!visited[i]) {
				visited[i] = true;
				B.push(i);
			}
		}
	}
}
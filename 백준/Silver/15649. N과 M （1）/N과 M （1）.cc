#include <iostream>
using namespace std;

static int N, M;
static bool visited[8];
static int seq[8];

void backtracking(int length);

int main() {
    cin >> N >> M;
    backtracking(0);
}

void backtracking(int length) {
    if (length == M) {
        for (int i = 0; i < M; i++) {
            cout << seq[i] + 1 << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            seq[length] = i;
            backtracking(length + 1);
            visited[i] = false;
        }
    }
}
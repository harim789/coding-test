#include <cmath>
#include <iostream>
using namespace std;

static int A[15];
static int N;
static int cnt = 0;
void backtracking(int row);
bool check(int row);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    backtracking(0);

    cout << cnt << "\n";
}

void backtracking(int row) {
	if (row == N) {
		cnt++;
		return;
	}

    for (int i = 0; i < N; i++) {
        A[row] = i;
        if (check(row)) {
            backtracking(row + 1);
        }
    }
}

bool check(int row) {
    for (int i = 0; i < row; i++) {
        if (A[i] == A[row]) return false;
        if (abs(i - row) == abs(A[i] - A[row])) return false;
    }
    return true;
}
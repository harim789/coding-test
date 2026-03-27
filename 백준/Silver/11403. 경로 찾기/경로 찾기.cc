#include <iostream>
#include <vector>
using namespace std;

int dim[100];
vector<vector<int>> A;
vector<bool> visited;
void dfs(int a);

int main() {
    int n;
    cin >> n;

	A.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int su;
            cin >> su;

            if (su == 1) {
                A[i].push_back(j);
            }
        }
    }

	visited.resize(n);
    for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			visited[k] = false;
			dim[k] = 0;
		}
        dfs(i);
		for (int j = 0; j < n; j++) {
			cout << dim[j] << ' ';
		}
		cout << '\n';
    }
}

void dfs(int a) {
	if (visited[a]) return;

	visited[a] = true;

	for (int i: A[a]) {
		dim[i] = 1;
		dfs(i);
	}
}
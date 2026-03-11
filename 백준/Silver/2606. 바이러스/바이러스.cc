#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> A;
vector<bool> visited;
void dps(int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int com_num, pair;
    cin >> com_num >> pair;

    A.resize(com_num + 1);
    visited = vector<bool>(com_num + 1);

    for (int i = 0; i < pair; i++) {
        int s, e;
        cin >> s >> e;

        A[s].push_back(e);
        A[e].push_back(s);
    }

	dps(1);

	int virus = 0;
	for (int i = 2; i <= com_num; i++) {
		if (visited[i]) {
			virus++;
		}
	}

	cout << virus << '\n';
}

void dps(int n) {
	if (visited[n]) {
		return;
	}

	visited[n] = true;

	for(int i: A[n]) {
		if (!visited[i]) {
			dps(i);
		}
	}
}

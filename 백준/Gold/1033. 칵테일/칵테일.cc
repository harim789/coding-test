#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

vector<tuple<int, int, int>> A[10];
bool visited[10];
long D[10];
long gcd(long a, long b);
void DFS(int node);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    long lcm = 1;

    for (int i = 0; i < N - 1; i++) {
        int a, b, p, q;
        cin >> a >> b >> p >> q;

        A[a].push_back(make_tuple(b, p, q));
        A[b].push_back(make_tuple(a, q, p));

        lcm *= (p * q / gcd(p, q));
    }

    D[0] = lcm;
    DFS(0);
	long mgcd = D[0];

	for (int i = 1; i < N; i++) {
		mgcd = gcd(mgcd, D[i]);
	}

	for (int i = 0; i < N; i++) {
		cout << D[i] / mgcd << ' ';
	}

	cout << '\n';
}

long gcd(long a, long b) {
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

void DFS(int node) {
    visited[node] = true;

    for (tuple<int, int, int> i : A[node]) {
        int next = get<0>(i);
        if (!visited[next]) {
            D[next] = D[node] / get<1>(i) * get<2>(i);
			DFS(next);
        }
    }
}
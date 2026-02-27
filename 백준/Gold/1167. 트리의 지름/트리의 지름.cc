#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> edge;
static vector<bool> visited;
static vector<vector<edge>> A;
static vector<int> m_distance;
void BFS(int start);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    A.resize(N + 1);
    for (int i = 0; i < N; i++) {
        int start_v;
        cin >> start_v;
        int end_v, distance;
        while (1) {
            cin >> end_v;
            if (end_v == -1) {
                break;
            } else {
                cin >> distance;
            }
            A[start_v].push_back(edge(end_v, distance));
        }
    }

    m_distance = vector<int>(N + 1, 0);
    visited = vector<bool>(N + 1, false);
	BFS(1);
	int Max = 1;

	for (int i = 2; i <= N; i++) {
		if (m_distance[Max] < m_distance[i]) {
			Max = i;
		}
	}

    fill(m_distance.begin(), m_distance.end(), 0);
	fill(visited.begin(), visited.end(), false);
	BFS(Max);
	sort(m_distance.begin(), m_distance.end(), greater<int>());

	cout << m_distance[0] << '\n';
}

void BFS(int start) {
    queue<int> myQueue;
    myQueue.push(start);
    visited[start] = true;

    while (!myQueue.empty()) {
        int now_node = myQueue.front();
        myQueue.pop();

        for (edge e : A[now_node]) {
            if (!visited[e.first]) {
                visited[e.first] = true;
                myQueue.push(e.first);
                m_distance[e.first] = m_distance[now_node] + e.second;
            }
        }
    }
}
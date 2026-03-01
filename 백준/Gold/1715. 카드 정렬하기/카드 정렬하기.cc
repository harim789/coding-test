#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

	// greater<int> 적용 시
	//  - sort(vector 등)에서는 내림차순
	//  - priority_queue에서는 오름차순 (작은 값이 top)
    priority_queue<int, vector<int>, greater<int>> asc_queue;
    for (int i = 0; i < N; i++) {
		int card_bundle;
        cin >> card_bundle;
		asc_queue.push(card_bundle);
    }

	long compare_sum = 0;
	while (asc_queue.size() != 1) {
		int first_min, second_min;

		first_min = asc_queue.top();
		asc_queue.pop();
		second_min = asc_queue.top();
		asc_queue.pop();

		int min_sum = first_min + second_min;
		compare_sum += min_sum;
		asc_queue.push(min_sum);
	}

	cout << compare_sum << '\n';
}
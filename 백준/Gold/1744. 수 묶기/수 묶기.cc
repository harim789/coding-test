#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> minus_queue;
    priority_queue<int> plus_queue;

	int one_num = 0;
    for (int i = 0; i < N; i++) {
        int data;
        cin >> data;

        if (data <= 0) {
            minus_queue.push(data);
        } else if (data == 1) {
			one_num++;
		} else {
            plus_queue.push(data);
        }
    }

    int sum = 0;
    // 음수 처리
    while (minus_queue.size()) {
        if (minus_queue.size() >= 2) {
            int first_min, second_min;
            first_min = minus_queue.top();
            minus_queue.pop();
            second_min = minus_queue.top();
            minus_queue.pop();

            sum += (first_min * second_min);
        } else if (minus_queue.size() == 1) {
            sum += minus_queue.top();
            minus_queue.pop();
        }
    }

	// 1 처리
	sum += one_num;

    // 양수 처리
    while (plus_queue.size()) {
        if (plus_queue.size() >= 2) {
            int first_max, second_max;
            first_max = plus_queue.top();
            plus_queue.pop();
            second_max = plus_queue.top();
            plus_queue.pop();

            sum += (first_max * second_max);
        } else if (plus_queue.size() == 1) {
            sum += plus_queue.top();
            plus_queue.pop();
        }
    }

    cout << sum << '\n';
}
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<int> A(N, 0);

    // start = 가장 큰 수(가장 마지막에 입력한 수)
    // end = 입력한 수들의 합
    int start = 0;
    int end = 0;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (start < A[i]) {
            start = A[i];
        }
        end += A[i];
    }

	// while: start <= end 이면 반복
		// (start + end) / 2 를 mid로 설정
		// 0 ~ N-1 까지 돌아가면서 블루레이 개수 세기
			// sum += A[i]
			// 만약 sum이 mid 보다 크다면 count++, sum = A[i]
		// 만약 sum != 0 이라면 count++
		// 만약 count <= M 이라면 end = mid-1
		// 아니라면 (else) start = mid+1

    while (start <= end) {
        int sum = 0;
        int count = 0;
        int mid = (start + end) / 2;

        for (int i = 0; i < N; i++) {
            sum += A[i];
            if (sum > mid) {
                count++;
                sum = A[i];
            }
        }
        if (sum != 0) {
            count++;
        }
        if (count <= M) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    cout << start << '\n';
}
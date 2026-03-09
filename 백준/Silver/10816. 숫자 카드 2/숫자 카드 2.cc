#include <iostream>
#include <vector>
using namespace std;

// int A[10000000]와 B[10000001]처럼 거대한 배열을 스택(Stack) 영역에 선언하면 메모리 제한을 금방 넘김
// 거대한 배열을 사용해야 한다면 전역 변수로 빼거나 std::vector를 사용해야함!!
// 전역 변수는 힙/데이터 영역을 사용하여 훨씬 넉넉한 공간을 제공
int A[10000000] = {0};
int B[10000001] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int su;
        cin >> su;

        if (su < 0) {
            A[-1 * su]++;
        } else {
            B[su]++;
        }
    }

    int m;
    cin >> m;
    vector<int> count(m);

    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;

        if (num < 0) {
            count[i] = A[-1 * num];
        } else {
            count[i] = B[num];
        }
    }

    for (int i = 0; i < m; i++) {
        cout << count[i] << ' ';
    }
    cout << '\n';
}
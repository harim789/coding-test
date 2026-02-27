#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

static int m[10][10];
static int remain[6] = {0, 5, 5, 5, 5, 5};
static int result = INT_MAX;
void backtracking(int xy, int useCnt);
bool check_size(int x, int y, int size);
void fill(int x, int y, int size, int fill_num);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> m[i][j];
        }
    }

    backtracking(0, 0);

    if (result == INT_MAX) {
        cout << -1 << '\n';
    } else {
        cout << result << '\n';
    }
}

void backtracking(int xy, int useCnt) {
    // 만약 xy = 100이면 min result 구하고 종료
    if (xy == 100) {
        result = min(result, useCnt);
		return;
    }

    // x, y 구하기 (x = xy / 10, y = xy % 10)
    int x = xy / 10;
    int y = xy % 10;

    if (result <= useCnt) return;

    // m[x][y] = 1 인 경우
    // 5~1까지 반복
    // -> 그 안에서 check_size를 만족하면서 해당 사이즈 사용 가능하면
    // -> 사용 개수 늘리기, 0으로 변경, backtracking 재귀
    // -> 재귀 후 (재귀 함수 종료 후) 사용 개수 다시 줄이기, 다시 1로 채우기

    // m[x][y] != 1 인 경우
    // backtracking 재귀 (xy만 1 늘리고, useCnt는 그대로)

    if (m[x][y] == 1) {
        for (int i = 5; i >= 1; i--) {
            if (remain[i] && check_size(x, y, i)) {
                remain[i]--;
                fill(x, y, i, 0);
                backtracking(xy + 1, useCnt + 1);
                remain[i]++;
                fill(x, y, i, 1);
            }
        }
    } else {
        backtracking(xy + 1, useCnt);
    }
}

// 사이즈 체크 (5, 4, 3, 2, 1)
bool check_size(int x, int y, int size) {
    // x+size 또는 y+size가 10보다 크면 false
    // 해당 사이즈의 사각형이 모두 1인지 체크 -> true / false
    if (x + size > 10 || y + size > 10) return false;
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (m[i][j] != 1) return false;
        }
    }
    return true;
}

void fill(int x, int y, int size, int fill_num) {
    // 해당 사이즈의 원소들을 fill_num으로 변경
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            m[i][j] = fill_num;
        }
    }
}
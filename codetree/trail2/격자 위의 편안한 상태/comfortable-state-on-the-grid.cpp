#include <iostream>
#include <vector>
using namespace std;

int n;
// vector<vector<int>> mat(n);
/* -> 이렇게 하면 전역 변수 n은 이 시점에 0으로 초기화되어 있다. 
      그래서 mat(n)은 mat(0), 즉 크기 0짜리 벡터가 만들어진다. 
      이후 main에서 n에 값을 입력받아도 mat의 크기는 자동으로 바뀌지 않는다.

      그 상태에서 mat[i].resize(n, 0)을 호출하면 존재하지 않는 mat[i]에 접근하게 되어 런타임 에러가 난다.

    해결: n을 입력받은 뒤에 mat의 크기를 정한다!
*/

vector<vector<int>> mat;

bool inRange(int r, int c) {
    return (r >= 1 && r < n + 1 && c >= 1 && c < n + 1);
}

bool isComfortable(int r, int c) {
    int cnt = 0;

    if (inRange(r - 1, c) && mat[r - 1][c] == 1) {
        cnt++;
    } 
    if (inRange(r, c + 1) && mat[r][c + 1] == 1) {
        cnt++;
    } 
    if (inRange(r + 1, c) && mat[r + 1][c] == 1) {
        cnt++;
    } 
    if (inRange(r, c - 1) && mat[r][c - 1] == 1) {
        cnt++;
    }

    return (cnt == 3);
}

int main() {
    int m;
    cin >> n >> m;

    mat.resize(n + 1);
    for (int i = 0; i < n + 1; i++) {
        mat[i].resize(n + 1, 0);
    }

    int r[m];
    int c[m];

    for (int i = 0; i < m; i++) {
        cin >> r[i] >> c[i];
        mat[r[i]][c[i]] = 1;
        
        if (isComfortable(r[i], c[i])) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}
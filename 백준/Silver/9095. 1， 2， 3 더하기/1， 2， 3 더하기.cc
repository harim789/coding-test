#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    int dp[12];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    // i의 방법의 수를 구하는 방법
    // i-3의 방법의 수에서 + 3을 하는 방법 1개
    // i-2의 방법의 수에서 + 2를 하는 방법 1개
    // i-1의 방법의 수에서 + 1를 하는 방법 1개
    // => dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
    for (int i = 4; i <= 11; i++) {
        dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
    }

    for (int i = 0;i < t; i++) {
        int n;
        cin >> n;

        cout << dp[n] << '\n';
    }
}
#include <cmath>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool isPalindrome(int i);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int max = 1003001;
    int N;
    cin >> N;
    vector<int> A(max);

    for (int i = 2; i <= max; i++) {
        A[i] = i;
    }

    for (int i = 2; i <= sqrt(max); i++) {
        if (A[i] == 0) {
            continue;
        }
        for (int j = i + i; j <= max; j += i) {
            A[j] = 0;
        }
    }

    for (int i = N; i <= max; i++) {
		if (i == 1) continue;
        if (A[i] != 0 && isPalindrome(i)) {
            cout << i << '\n';
            return 0;
        }
    }
}

bool isPalindrome(int i) {
    string str_su = to_string(i);
    int len = str_su.length();

    for (int i = 0; i < len / 2; i++) {
        if (str_su[i] != str_su[len - i - 1]) {
            return false;
        }
    }

    return true;
}
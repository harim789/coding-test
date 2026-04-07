#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {
        string str;
        // cin >> str;

		// 엔터(\n)가 나올 때까지 중간에 있는 모든 공백을 포함해서 한꺼번에 읽어올 때는
		// getline(cin, str) 사용!!
		getline(cin, str);

		if (str == "***") break;

        reverse(str.begin(), str.end());

        cout << str << '\n';
    }
}
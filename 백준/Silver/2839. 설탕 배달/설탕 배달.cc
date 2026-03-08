#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

	int num_5 = n / 5;
	bool isExist = false;
	int count = 0;

    while (num_5 > 0) {
        int remain = n - 5 * num_5;

        if (remain % 3 == 0) {
			count = num_5 + (remain / 3);
            cout << count << '\n';
			isExist = true;
            break;
        } else {
			num_5--;
		}
    }

	if (!count && n % 3 == 0) {
		cout << n / 3 << '\n';
		isExist = true;
	}

	if (!isExist) {
		cout << -1 << '\n';
	}
}
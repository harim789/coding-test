#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int num_2 = 0;
    int num_5 = 0;

    for (int i = n; i > 0; i--) {
		int temp = i;
        while (temp % 2 == 0) {
            num_2++;
            temp /= 2;
        }

        while (temp % 5 == 0) {
            num_5++;
            temp /= 5;
        }
    }

    int count = 0;
    while (num_2 && num_5) {
        count++;
        num_2--;
        num_5--;
    }

    cout << count << '\n';
}
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int mul = 1;
    int div = 1;
    for (int i = 0; i < k; i++) {
        mul *= (n - i);
        div *= (i + 1);
    }

	cout << mul / div << '\n';
}
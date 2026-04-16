#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

	int carlos;
	cin >> carlos;

	bool isElected = true;
    for (int i = 0; i < n-1; i++) {
		int su;
		cin >> su;

		if (carlos < su) {
			isElected = false;
			break;
		}
    }

	if (isElected) {
		cout << "S\n";
	} else {
		cout << "N\n";
	}
}
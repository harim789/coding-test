#include <iostream>
using namespace std;

int main() {
    int N;
	cin >> N;

    int score[N + 1];
    int max = 0;
	int sum = 0;

    for (int i = 0; i < N; i++) {
        cin >> score[i];
        if (max < score[i]) {
			max = score[i];
		}
		sum += score[i];
    }

	double manipulate_ave = sum * 100.0 / max / N;
	cout << manipulate_ave << "\n";

    return 0;
}
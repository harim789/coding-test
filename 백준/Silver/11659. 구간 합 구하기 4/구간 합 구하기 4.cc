#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int suNo = 0;
	int quizNo = 0;
	cin >> suNo >> quizNo;

	int A = 0;
	int S[100001] = {0};
	for (int i = 1; i <= suNo; i++) {
		cin >> A;
		S[i] = S[i-1] + A;
	}

	int start = 0;
	int end = 0;
	for (int i = 0; i < quizNo; i++) {
		cin >> start >> end;
		cout << S[end] - S[start-1] << "\n";
	}

	return 0;
}
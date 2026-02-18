#include <iostream>
#include <deque>
using namespace std;

int main() {
	int N;
	cin >> N;

	deque<int> myDeque;
	for (int i = N; i > 0; i--) {
		myDeque.push_back(i);
	}

	for (int i = 0; i < N-2; i++) {
		myDeque.pop_back();
		int moveFront = myDeque.back();
		myDeque.pop_back();
		myDeque.push_front(moveFront);
	}

	cout << myDeque.front() << "\n";
}
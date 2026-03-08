#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool compare(string a, string b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    } else {
        return a < b;
    }
}

int main() {
    int n;
    cin >> n;

    vector<string> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end(), compare);

	A.erase(unique(A.begin(), A.end()), A.end());
	
	for(int i = 0; i < A.size(); i++) {
		cout << A[i] << '\n';
	}

	// cout << A[0] << '\n';
    // for (int i = 1; i < n; i++) {
	// 	if (A[i] == A[i-1]) {
	// 		continue;
	// 	}
    //     cout << A[i] << '\n';
    // }
}
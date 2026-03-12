#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<string> A;
        vector<int> B;

        for (int i = 0; i < n; i++) {
            string cloth, type;
            cin >> cloth >> type;

            bool alreadyExist = false;
            int idx = 0;
            for (int j = 0; j < A.size(); j++) {
                if (A[j] == type) {
                    alreadyExist = true;
                    idx = j;
                    break;
                }
            }
            if (!alreadyExist) {
                A.push_back(type);
				B.push_back(1);
            } else {
				B[idx]++;
			}
        }

        int result = 1;

        for (int j = 0; j < A.size(); j++) {
            result *= (B[j] + 1);
        }

        cout << result - 1 << '\n';
    }
}
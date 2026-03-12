#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int gasu(int su);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << gasu(n) << '\n';
    }
}

int gasu(int su) {
    int max_num_3 = su / 3;
    vector<tuple<int, int, int>> A;

    for (int i = max_num_3; i >= 0; i--) {
        int r_3 = su - i * 3;
        int max_num_2 = r_3 / 2;
        for (int j = max_num_2; j >= 0; j--) {
            int one = su - i * 3 - j * 2;
            A.push_back({i, j, one});
        }
    }

    int num_hap = 0;
    for (int i = 0; i < A.size(); i++) {
        int num_3 = get<0>(A[i]);
        int num_2 = get<1>(A[i]);
        int num_1 = get<2>(A[i]);

        int each_hap = 1;

        for (int j = num_3 + num_2 + num_1; j >= 1; j--) {
            each_hap *= j;
        }

        for (int j = num_3; j >= 1; j--) {
            each_hap /= j;
        }

        for (int j = num_2; j >= 1; j--) {
            each_hap /= j;
        }

        for (int j = num_1; j >= 1; j--) {
            each_hap /= j;
        }

        num_hap += each_hap;
    }

    return num_hap;
}
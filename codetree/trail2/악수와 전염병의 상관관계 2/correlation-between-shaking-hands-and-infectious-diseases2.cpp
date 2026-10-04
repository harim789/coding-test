#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
    int n, k, p, t;
    cin >> n >> k >> p >> t;

    vector<bool> infection(n + 1, false);
    vector<int> resident_k(n + 1, 0);

    infection[p] = true;
    resident_k[p] = k;

    // vector에 tuple 삽입
    vector<tuple<int, int, int>> handshake;

    for (int i = 0; i < t; i++) {
        int sec, person_1, person_2;
        cin >> sec >> person_1 >> person_2;

        // make_tuple
        handshake.push_back(make_tuple(sec, person_1, person_2));
    }

    // sort -> tuple의 첫 요소로 정렬
    sort(handshake.begin(), handshake.end());

    // for (int i = 0; i < t; i++) {
    //     cout << get<0>(handshake[i]) << get<1>(handshake[i]) << get<2>(handshake[i]) << endl;
    // }

    for (int i = 0; i < t; i++) {
        int person_1 = get<1>(handshake[i]);
        int person_2 = get<2>(handshake[i]);

        if (infection[person_1] && resident_k[person_1] > 0 && !infection[person_2]) {
            resident_k[person_1]--;
            infection[person_2] = true;
            resident_k[person_2] = k;

        } else if (infection[person_2] && resident_k[person_2] > 0 && !infection[person_1]) {
            resident_k[person_2]--;
            infection[person_1] = true;
            resident_k[person_1] = k;
        } else if ((infection[person_1] && resident_k[person_1] > 0) || (infection[person_2] && resident_k[person_2] > 0)) {
            if (resident_k[person_1] > 0) {
                resident_k[person_1]--;
            }

            if (resident_k[person_2] > 0) {
                resident_k[person_2]--;
            }
        }
    }

    for (int i = 1; i < n + 1; i++) {
        if (infection[i]) {
            cout << 1;
        } else {
            cout << 0;
        }
    }

    return 0;
}
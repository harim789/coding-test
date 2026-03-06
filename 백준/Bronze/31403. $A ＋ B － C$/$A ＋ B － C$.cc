#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    int i_sum = 0;
    string str_sum = "";
    int final_str_sum = 0;

    for (int i = 0; i < 3; i++) {
        cin >> str;
        if (i != 2) {
            i_sum += stoi(str);
            str_sum += str;
        } else {
            i_sum -= stoi(str);
            int sub_su = stoi(str);
            final_str_sum = stoi(str_sum) - sub_su;
        }
    }

    cout << i_sum << '\n';
    cout << final_str_sum << '\n';
}
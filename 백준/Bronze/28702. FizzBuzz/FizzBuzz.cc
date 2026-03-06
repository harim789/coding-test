#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> str(3);

    int su_index;
    int su;
    for (int i = 0; i < 3; i++) {
        cin >> str[i];
        if (str[i] != "Fizz" && str[i] != "Buzz" && str[i] != "FizzBuzz") {
            su_index = i;
            su = stoi(str[i]);
        }
    }

    int res_su = su + (3 - su_index);
    string str_res_su = to_string(res_su);
    int len = str_res_su.length();

    bool isMulThree = false;
    bool isMulFive = false;

    int jarisu_hap = 0;
    for (int i = 0; i < len; i++) {
        jarisu_hap += str_res_su[i];
    }
    if (jarisu_hap % 3 == 0) isMulThree = true;
    if (str_res_su[len-1] == '0' || str_res_su[len-1] == '5') isMulFive = true;

    if (isMulThree && isMulFive) {
        cout << "FizzBuzz" << '\n';
    } else if (isMulThree) {
        cout << "Fizz" << '\n';
    } else if (isMulFive) {
		cout << "Buzz" << '\n';
	} else {
		cout << str_res_su << '\n';
	}
}
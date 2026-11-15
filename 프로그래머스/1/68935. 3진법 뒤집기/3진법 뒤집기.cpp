#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int solution(int n) {
    int jarisu = 0;
    int dividend = n;
    while (dividend / 3 != 0) {
        dividend /= 3;
        jarisu++;
    }
    
    int zegopsu = pow(3, jarisu);
    string str_digit_3;
    int q;
    for (int i = 0; i < jarisu + 1; i++) {
        q = n / zegopsu;
        str_digit_3 += to_string(q);
        if (q > 0) {
            n -= zegopsu * q;
        }
        zegopsu /= 3;
    }
    // cout << str_digit_3;
    
    reverse(str_digit_3.begin(), str_digit_3.end());
    // cout << str_digit_3;
    
    int ans = 0;
    for (int i = 0; i <= jarisu; i++) {
        // int a = str_digit_3[jarisu - i] - '0';
        // cout << a;
        
        ans += (str_digit_3[jarisu - i] - '0') * pow(3, i);
    }
    return ans;
}
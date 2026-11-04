#include <iostream>
#include <vector>
using namespace std;

bool carry(string a, string b, string c) {
    for (int i = 0; i < 5; i++) {
        int num1 = a[i] - '0';
        int num2 = b[i] - '0';
        int num3 = c[i] - '0';

        if (num1 + num2 + num3 >= 10) return true;
    }

    return false;
}

int main () {
    int n;
    cin >> n;
    
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = "00000";
    }

    for (int i = 0; i < n; i++) {
        string str_num;
        cin >> str_num;

        int len = str_num.length();

        for (int j = 0; j < len; j++) {
            v[i][5 - len + j] = str_num[j];
        }
        
        // cout << v[i] << endl;
    }

    int max = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (!carry(v[i], v[j], v[k])) {
                    // cout << v[i] << ' ' << v[j] << ' ' << v[k] << endl;
                    int sum = stoi(v[i]) + stoi(v[j]) + stoi(v[k]);
                    if (max < sum) max = sum;
                }
            }
        }
    }

    cout << max;
}
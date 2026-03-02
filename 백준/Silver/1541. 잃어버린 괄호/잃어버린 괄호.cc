#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(string input, char delimiter);
int mySum(string str);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string sik;
    cin >> sik;
    int answer = 0;

    vector<string> str = split(sik, '-');

    for (int i = 0; i < str.size(); i++) {
        int temp = mySum(str[i]);

        if (i == 0) {
            answer += temp;
        } else {
            answer -= temp;
        }
    }

    cout << answer << '\n';
}

vector<string> split(string input, char delimiter) {
    vector<string> result;
    stringstream mystream(input);
    string splitdata;

    while (getline(mystream, splitdata, delimiter)) {
        result.push_back(splitdata);
    }

    return result;
}

int mySum(string str) {
    vector<string> su = split(str, '+');
    int sum = 0;

    for (int i = 0; i < su.size(); i++) {
        sum += stoi(su[i]);
    }

    return sum;
}
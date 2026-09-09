#include <iostream>
#include <vector>
#include <string>
#include <regex>
using namespace std;

int solution(string s) {
    vector<string> number = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    for (int i = 0; i < 10; i++) {
        s = regex_replace(s, regex(number[i]), to_string(i));
    }
    
    return stoi(s);
}
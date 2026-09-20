#include <string>
using namespace std;

string solution(string phone_number) {
    string result = phone_number;
    int len = phone_number.length();
    
    for (int i = 0; i < len - 4; i++) {
        result[i] = '*';
    }
    
    return result;
}
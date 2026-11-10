#include <string>
using namespace std;

string solution(int n) {
    int repeat = n / 2;
    
    string ans;
    for (int i = 0; i < repeat; i++) {
        ans += "수박";
    }
    
    if (n % 2 != 0) {
        ans += "수";
    }
    
    return ans;
}
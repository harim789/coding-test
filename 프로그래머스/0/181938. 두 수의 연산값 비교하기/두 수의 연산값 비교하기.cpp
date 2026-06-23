#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int a, int b) {
    string str = to_string(b);
    int len = str.length();
    
    int ans1 = a * pow(10, len) + b;
    int ans2 = 2 * a * b;
    
    int answer = ans1 > ans2 ? ans1 : ans2;
    return answer;
}
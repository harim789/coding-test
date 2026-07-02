#include <vector>
#include <string>
using namespace std;

string solution(vector<string> seoul) {
    
    int result;
    for (int i = 0; i < seoul.size(); i++) {
        if (seoul[i] == "Kim") {
            result = i;
            break;
        }
    }
    
    return "김서방은 " + to_string(result) + "에 있다";
}
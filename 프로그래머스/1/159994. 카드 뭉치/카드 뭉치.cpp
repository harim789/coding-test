#include <vector>
#include <string>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int idx1 = 0;
    int idx2 = 0;
    
    for (string g: goal) {
        if (g == cards1[idx1]) {
            idx1++;
        } else if (g == cards2[idx2]) {
            idx2++;
        } else {
            return "No";
        }
    }
    
    return "Yes";
}
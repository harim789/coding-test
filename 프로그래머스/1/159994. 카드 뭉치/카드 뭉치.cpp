#include <vector>
#include <string>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int size = goal.size();
    int idx1 = 0;
    int idx2 = 0;
    
    int i = 0;
    while ((idx1 < cards1.size()) && (idx2 < cards2.size()) && i < size) {
        if (goal[i] == cards1[idx1]) {
            idx1++;
        } else if (goal[i] == cards2[idx2]) {
            idx2++;
        } else {
            return "No";
        }
        i++;
    }
    
    if (i == size) return "Yes";
    
    if (idx1 < cards1.size()) {
        while (idx1 < cards1.size()) {
            if (cards1[idx1] == goal[i]) {
                idx1++;
            } else {
                return "No";
            }
            i++;
        }
    }
        
    if (i == size) return "Yes";
    
    if (idx2 < cards2.size()) {
        while (idx2 < cards2.size()) {
            if (cards2[idx2] == goal[i]) {
                idx2++;
            } else {
                return "No";
            }
            i++;
        }
    }
    
    if (i != goal.size()) return "No";
           
    return "Yes";
}
#include <string>
using namespace std;

bool solution(string s) {
    int p_su = 0;
    int y_su = 0;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'p' || s[i] == 'P') {
            p_su++;
        } 
        
        if (s[i] == 'y' || s[i] == 'Y') {
            y_su++;
        } 
    }
    
    if (p_su != y_su) {
        return false;
    } else {
        return true;
    }
}
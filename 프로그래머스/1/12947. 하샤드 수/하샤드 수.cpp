#include <string>
using namespace std;

bool solution(int x) {
    string s = to_string(x);
    
    int jarisu_hap = 0;
    for(int i = 0; i < s.length(); i++) {
        jarisu_hap += s[i] - '0';
    }
    
    return !(x % jarisu_hap);
}
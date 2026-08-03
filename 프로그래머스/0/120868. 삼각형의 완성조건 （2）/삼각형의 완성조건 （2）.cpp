#include <vector>
using namespace std;

int solution(vector<int> sides) {
    int max = sides[0];
    int min = sides[1];
    
    if (sides[0] < sides[1]) {
        max = sides[1];
        min = sides[0];
    }
    
    int res = 0;
    
    if (max == min) {
        res = 2 * max - 1;
    } else {
        for (int i = 1; i < max; i++) {
            if (min + i > max) res++;
        }
        
        for (int i = max; i < min + max; i++) {
            res++;
        }
    }
    
    return res;
}
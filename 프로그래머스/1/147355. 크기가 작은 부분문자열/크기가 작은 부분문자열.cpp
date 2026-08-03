#include <string>
using namespace std;

int solution(string t, string p) {
    int t_size = t.size();
    int p_size = p.size();
    long long ip = stol(p);
    
    int res = 0;
    for (int i = 0; i < t_size - p_size + 1; i++) {
        string str_part = t.substr(i, p_size);
        long long i_part = stol(str_part);
        
        if (i_part <= ip) res++;
    }
    
    return res;
}
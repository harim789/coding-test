#include <vector>
using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int sum = 0;
    
    for (int i = 0; i < signs.size(); i++) {
        int cur = signs[i] == 1 ? absolutes[i] : absolutes[i] * (-1);
        sum += cur;
    }
    
    return sum;
}
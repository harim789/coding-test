#include <vector>
using namespace std;

int solution(vector<int> numbers) {
    int result = 45;
    
    for (int i = 0; i < numbers.size(); i++) {
        result -= numbers[i];
    }
    
    return result;
}
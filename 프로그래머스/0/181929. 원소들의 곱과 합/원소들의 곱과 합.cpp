#include <iostream>
#include <vector>
using namespace std; 

int solution(vector<int> num_list) {
    int sum = 0;
    int mul = 1;
    
    for (int num: num_list) {
        sum += num;
        mul *= num;
    }
    
    int result = (mul < sum * sum);
    return result;
}
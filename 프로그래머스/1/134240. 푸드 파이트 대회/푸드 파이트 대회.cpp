#include <vector>
#include <string>
#include <iostream>

using namespace std;

string solution(vector<int> food) {
    int len = 1;
    string ans = "0";
    
    for (int i = 1; i < food.size(); i++) {
        int each_gasu = 0;
        each_gasu += (food[i] / 2) * 2;
        len += each_gasu;
        for (int i = 0; i < each_gasu; i++) {
            ans += "0";
        }
    }
    
    cout << ans << '\n';
    
    int index = 0;
    for (int i = 1; i < food.size(); i++) {
        int gasu = food[i] / 2;
        
        for (int j = 0; j < gasu; j++) {
            ans[index] = i + '0';
            ans[len - index - 1] = i + '0';
            
            index++;
        }
    }
    
    return ans;
}
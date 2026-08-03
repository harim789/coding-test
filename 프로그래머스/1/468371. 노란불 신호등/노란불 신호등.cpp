#include <vector>
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int solution(vector<vector<int>> signals) {
    int n = signals.size();
    
    
    int hap1 = signals[0][0] + signals[0][1] + signals[0][2];
    int hap2 = signals[1][0] + signals[1][1] + signals[1][2];
    int gcd_su = gcd(hap1, hap2);
    int lcm = hap1 / gcd_su * hap2;
    
    for (int i = 2; i < n; i++) {
        hap1 = lcm;
        hap2 = signals[i][0] + signals[i][1] + signals[i][2];
        
        gcd_su = gcd(hap1, hap2);
        lcm = hap1 / gcd_su * hap2;
    }
    
    int min_index = n - 1;
    int min = lcm / hap2 * signals[n-1][1];
    for (int i = 0; i < n - 1; i++) {
        int hap = signals[i][0] + signals[i][1] + signals[i][2];
        int temp_min = lcm / hap * signals[i][1];
        
        if (temp_min < min) {
            min_index = i;
            min = temp_min;
        }
    }
    
    vector<int> repeat(n);
    for (int i = 0; i < n; i++) {
        repeat[i] = signals[i][0] + signals[i][1] + signals[i][2];
    }
    
    for (int i = 1; i <= lcm; i++) {
        vector<bool> flag(n);
        
        for (int j = 0; j < n; j++) {
            int yellow_start = signals[j][0] + 1;
            int yellow_end = yellow_start + signals[j][1] - 1;
            if (i % repeat[j] >= yellow_start && i % repeat[j] <= yellow_end) {
                flag[j] = true;
            }
        }
        
        bool exist = true;
        for (int j = 0; j < n; j++) {
            if (!flag[j]) {
                exist = false;
            }
        }
        
        if (exist) return i;
    }
    
    return -1;
}
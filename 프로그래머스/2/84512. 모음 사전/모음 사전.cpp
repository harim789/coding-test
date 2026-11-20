// A 1
// 10000

// AA 2
// 11000

// AAA 3
// 11100

// AAAA 4
// 11110

// AAAAA 5
// 11111

// AAAAE 6
// 11112


// AAAAI 7
// 11113    
    
// AAAE
// 1112 10

// 수가 5가 아니면 뒤에 0을 붙임, A -> U 순서대로 1, 2, 3, 4, 5

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string word) {
    vector<int> v;

    for (int i = 1; i <= 5; i++) {
        v.push_back(i * 10000);
    }

    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            int f = i * 10 + j;
            v.push_back(f * 1000);
        }
    }

    for (int a = 1; a <= 5; a++) {
        for (int b = 1; b <= 5; b++) {
            for (int c = 1; c <= 5; c++) {
                int f = a * 100 + b * 10 + c;
                v.push_back(f * 100);
            }
        }
    }

    for (int a = 1; a <= 5; a++) {
        for (int b = 1; b <= 5; b++) {
            for (int c = 1; c <= 5; c++) {
                for (int d = 1; d <= 5; d++) {             
                    int f = a * 1000 + b * 100 + c * 10 + d;
                    v.push_back(f * 10);   
                }
            }
        }
    }

    for (int a = 1; a <= 5; a++) {
        for (int b = 1; b <= 5; b++) {
            for (int c = 1; c <= 5; c++) {
                for (int d = 1; d <= 5; d++) { 
                    for (int e = 1; e <= 5; e++) {                    
                        int f = a * 10000 + b * 1000 + c * 100 + d * 10 + e;
                        v.push_back(f);  
                    } 
                }
            }
        }
    }

    sort(v.begin(), v.end());
    
    int size = word.size();
    
    string str;
    for (int i = 0; i < size; i++) {
        if (word[i] == 'A') {
            str += '1';
        } else if (word[i] == 'E') {
            str += '2';
        } else if (word[i] == 'I') {
            str += '3';
        } else if (word[i] == 'O') {
            str += '4';
        } else {
            str += '5';
        }
    }
    
    for (int i = 0; i < 5 - size; i++) {
        str += '0';
    }
    
    int i_word = stoi(str);
    
    int ans;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == i_word) {
            ans = i + 1;
            break;
        }
    }
    
    return ans;
    
}
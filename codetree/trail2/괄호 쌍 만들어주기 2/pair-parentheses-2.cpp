// 런타임 에러가 남!!!!

// 원인은 size_t(unsigned) 언더플로우였음
// : str.size()는 unsigned long 타입을 반환
//   -> 그래서 문자열 길이가 3 이하일 때:

// for (int i = 0; i < str.size() - 3; i++) 에서

// str.size() - 3이 음수가 되지 않고, 0 밑으로 내려가면서 엄청나게 큰 수가 되어버림!!!!

// -> 해결 방법
// int n = str.size();
// 를 통해 int로 변환해서 저장한 후 

// for (int i = 0; i < n - 3; i++)

// 를 하면 해결됨!!!!

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    int cnt = 0;
    int n = str.size();
    // for (int i = 0; i < str.size() - 3; i++) {
    for (int i = 0; i < n - 3; i++) {
        if (str[i] == '(' && str[i + 1] == '(') {
            for (int j = i + 2; j < str.size() - 1; j++) {
                if (str[j] == ')' && str[j + 1] == ')') cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}
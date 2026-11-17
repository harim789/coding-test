// vector v가 있을 때 중복 제거하는 법
// v.erase(unique(v.begin(), v.end()), v.end());

/*  1단계: unique는 실제로 지우지 않아요
    unique는 연속된 중복을 건너뛰면서 고유한 값들을 앞쪽으로 당겨 놓기만 합니다. 벡터 크기는 그대로예       요. 그리고 "고유한 값들이 끝나는 위치"(새 끝)를 반환합니다.

    처음:          [1, 1, 2, 2, 2, 3, 1]
    unique 후:     [1, 2, 3, 1, ?, ?, ?]
                               ↑
                            newEnd (반환값)

    ? 자리는 쓰레기값이에요. 무슨 값이 남아 있는지는 보장되지 않습니다.

    2단계: erase가 진짜로 잘라냅니다

    erase(newEnd, end())가 newEnd부터 끝까지를 실제로 삭제해서 크기를 줄여요.
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    int size = numbers.size();
    
    // vector<int> add;
    vector<int> ans;
    set<int> s;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            // add.push_back(numbers[i] + numbers[j]);
            s.insert(numbers[i] + numbers[j]);
        }
    }
    
    // sort(add.begin(), add.end());
    // add.erase(unique(add.begin(), add.end()), add.end());

    // return add;
    ans.assign(s.begin(), s.end());
    return ans;
}
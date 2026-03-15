#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    queue<int> A;
    
    for (int i = 1; i <= n; i++) {
        A.push(i);
    }
    
    for (int i = 0; i < n; i++) {
        int pop_num = A.front();
        A.pop();
        cout << pop_num << ' ';
        
        if (!A.size()) {
			cout << '\n';
            break;
        }
        int top = A.front();
        A.pop();
        A.push(top);
    }
}
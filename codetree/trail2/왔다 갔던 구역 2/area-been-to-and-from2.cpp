#include <iostream>
#include <vector>

using namespace std;

int n;
int x[100];
char dir[100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> dir[i];
    }

    vector<int> v(2001, 0);
    int cur = 0;
    
    for (int i = 0; i < n; i++) {
        if (dir[i] == 'L') {
            for (int j = 0; j < x[i]; j++) {
                v[cur + 1000 - 1]++;
                cur--;
            }   
        } else {
            for (int j = 0; j < x[i]; j++) {
                v[cur + 1000]++;
                cur++;
            } 
        }
    }

    int cnt = 0;
    for (int i = 0; i < 2000; i++) {
        if (v[i] >= 2) cnt++;
    }

    cout << cnt;

    return 0;
}
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
	vector<string> find_name(n+1);
    map<string, int> find_num;

    for (int i = 1; i <= n; i++) {
        string name;
        cin >> name;

		find_name[i] = name;
        find_num[name] = i;
    }

    for (int i = 0; i < m; i++) {
        string find;
        cin >> find;

        if (find[0] >= 'A' && find[0] <= 'Z') {
			cout << find_num[find] << '\n';
        } else {
            int num = stoi(find);
            cout << find_name[num] << '\n';
        }
    }
}
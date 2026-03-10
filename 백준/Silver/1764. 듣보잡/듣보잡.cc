#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	set<string> names;
	vector<string> finds;

	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;

		names.insert(name);
	}

	for (int i = 0; i < m; i++) {
		string find;
		cin >> find;
		if (names.find(find) != names.end()) {
			finds.push_back(find);
		}
	}
	sort(finds.begin(), finds.end());

	cout << finds.size() << '\n';
	for (int i = 0; i < finds.size(); i++) {
		cout << finds[i] << '\n';
	}
}
#include <cmath>
#include <iostream>
using namespace std;

int r, c;
int res;
void dc(int x, int y, int size);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n >> r >> c;

    dc(0, 0, pow(2, n));
}

void dc(int x, int y, int size) {
    if (x == c && y == r) {
        cout << res << '\n';
        return;
    } else if (c >= x && c < x + size && r >= y && r < y + size) {
        dc(x, y, size / 2);
        dc(x + size / 2, y, size / 2);
        dc(x, y + size / 2, size / 2);
        dc(x + size / 2, y + size / 2, size / 2);
    } else {
		res += size * size;
	}
}
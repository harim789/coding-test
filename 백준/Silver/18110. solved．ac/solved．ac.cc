#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

	if (n == 0) {
		cout << 0 << '\n';
		return 0;
	}
	
    vector<int> scores(n);

    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }
    sort(scores.begin(), scores.end());

    int i_15 = round(n * 0.15);
    int score_sum = 0;
    for (int i = i_15; i < n - i_15; i++) {
        score_sum += scores[i];
    }

	// int 끼리의 나눗셈은 소수점이 버려진 채로 나옴 (score_sum / (n - 2 * i_15))의 경우
	// => 나눗셈을 하기 전에 최소한 한쪽을 float나 double로 형변환(Casting) 해줘야 소수점 연산이 수행됨
    int i_ave = round((float)score_sum / (n - 2 * i_15));
	cout << i_ave << '\n';
}
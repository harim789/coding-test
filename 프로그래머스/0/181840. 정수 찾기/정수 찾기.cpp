#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

int solution (vector<int> num_list, int n) {
    return find(all(num_list), n) != num_list.end();
}
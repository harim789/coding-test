using namespace std;

int solution(int n) {
    if (n & 1) return 2;
    
    for (int i = 3; i < n; i += 2) {
        if (n % i == 1) return i;
    }
}
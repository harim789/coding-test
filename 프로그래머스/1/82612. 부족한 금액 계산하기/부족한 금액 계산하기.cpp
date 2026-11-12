#include <iostream>
using namespace std;

long long solution(int price, int money, int count) {
    long long total_price = 0;
    
    for (int i = 1; i <= count; i++) {
        total_price += price * i;
    }
    
    // long long prac_price = 0;
    // for (int i = 1; i < 2500; i++) {
    //     prac_price += 2500 * i;
    // }
    // cout << prac_price;
    // 이 경우 prac_price가 7809375000으로, int의 최댓값인 약 21억(2,147,483,647)을 넘는다.
    // -> total_price의 타입을 long long으로 바꾼 것까지는 잘 했으나, 반환 타입까지 long long으로 바꿔줘야 한다.
    
    if (total_price <= money) {
        return 0; 
    } else {
        return total_price - money;
    }
}
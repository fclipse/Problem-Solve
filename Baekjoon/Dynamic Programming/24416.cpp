// Baekjoon No. 24416 피보나치 수 1
// 재귀적으로 피보나치 함수를 구현했을때랑 DP 방식으로 구현했을때,
// 각각 수행되는 연산의 횟수를 구하는 알고리즘
// 재귀적으로 실행되는 횟수 == 실제 피보나치 수 임이 신기했음.
#include <iostream>
using namespace std;
int main(){
    int n, cnt1 = 0, cnt2 = 0, n_1 = 1, n_2 = 1;
    scanf("%d", &n);

    // 연산
    for(int i = 0; i < n - 2; i++){
        cnt1 = n_1 + n_2;
        n_1 = n_2;
        n_2 = cnt1;
    }
    cnt2 = n - 2;

    printf("%d %d", cnt1, cnt2);
    return 0;
}
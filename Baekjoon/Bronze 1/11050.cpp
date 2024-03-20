// Baekjoon No. 11050 이항 계수 1 - 220815 solved
// Time Complexity O(n)
// n, k가 주어질 때 nCk를 구하는 문제
#include <iostream>
#include <vector>
using namespace std;
int fact(int n);
int main(){
    ios::sync_with_stdio(false);
    int n, k;
    scanf("%d %d", &n, &k);

    // nCk == n! / k! * (n-k)!
    printf("%d", fact(n) / (fact(k) * fact(n-k)));
    return 0;
}
int fact(int n){
    if(n <= 1)
        return 1;
    else
        return fact(n-1) * n;
}
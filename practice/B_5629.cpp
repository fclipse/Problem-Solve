// Baekjoon No. 5692 팩토리얼 진법
// Time Complexity
// #dp사용, math

#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

long long factMemory[51] = { 0 };
long long factorial(int);

int main() {
    fastIO;
    unsigned long long n, res, i;
    while(true) {
        cin >> n;
        if (n == 0) break;
        res = 0;
        i = 1;
        while (n) {
            res += (n % 10) * factorial(i);
            i++;
            n /= 10;
        }
        cout << res << "\n";
    }

    return 0;
}
// 1
long long factorial(int n) {
    if (factMemory[n]) return factMemory[n];
    if (n == 1) return factMemory[1] = 1;
    return factMemory[n] = factorial(n - 1) * n;
}
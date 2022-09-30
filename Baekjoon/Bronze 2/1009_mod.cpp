// Baekjoon No. 1009 분산처리 - 220904 solved
// Time Complexity O(logn)
/*이전의 1009.cpp은 일의자리 나머지로만 판단했다면, 이번에는
* 이진수로 변환, 모듈러 연산은 곱에서의 분배법칙이 가능하다는 성질을 이용해
* 지수를 2^n의 합으로 표현, a^b => a^2^k1 * a^2^k2 * ... 형태로 바꾸어
* 큰 수의 나머지를 쉽게 구함.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, a, b, res;
    int i, j;
    int NSquares[32] = { 0 };
    cin >> t;

    for (i = 0; i < t; i++) {
        cin >> a >> b;
        res = 1;
        // init towNSquare
        NSquares[0] = (int)pow(a, 1) % 10;
        for (j = 1; j < 32; j++)
            NSquares[j] = NSquares[j - 1] * NSquares[j - 1] % 10;
        string number = bitset<32>(b).to_string();
        for (j = 0; j < 32; j++) {
            if (number[j] == '1') {
                res *= NSquares[31 - j];
                res %= 10;
            }
        }
        number.clear();
        if (!res)
            res = 10;
        cout << res;
    }
    return 0;
}
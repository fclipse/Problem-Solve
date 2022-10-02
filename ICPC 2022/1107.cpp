// Baekjoon No. 1107 리모컨 - 221001
// Time Complexity O(nlogn)
// # Brute Force

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#define SIZE 10
using namespace std;

int validate(int[SIZE], int);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    int n, m, minCnt, status, cmp;
    int i;
    cin >> n >> m;
    str = to_string(n);
    int buttonStatus[SIZE] = { 0 };
    for (i = 0; i < m; i++) {
        cin >> status;
        buttonStatus[status] = 1;   // ���峪�� 1
    }

    // solving
    minCnt = (100 > n) ? 100 - n : n - 100;
    if (minCnt > 0 && m < 10) {
        cmp = n;
        while (!validate(buttonStatus, cmp) && cmp > 0 && n - cmp + to_string(cmp).length() <= minCnt) cmp--;   // n�� length�� �ƴ� cmp�� length�� ���.
        if (n - cmp + to_string(cmp).length() < minCnt && validate(buttonStatus, cmp)) minCnt = n - cmp + to_string(cmp).length();
    }
    if(minCnt > 0 && m < 10) {
        cmp = n + 1;
        while (!validate(buttonStatus, cmp) && cmp - n + to_string(cmp).length() <= minCnt) cmp++;
        if (cmp - n + to_string(cmp).length() < minCnt && validate(buttonStatus, cmp)) minCnt = cmp - n + to_string(cmp).length();
    }

    cout << minCnt;

    return 0;
}
int validate(int buttonStatus[SIZE], int n) {
    string str = to_string(n);
    for (int i = 0; i < str.length(); i++) {
        if (buttonStatus[str[i] - '0'])
            return 0;
    }
    return 1;
}
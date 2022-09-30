// Baekjoon No. 13458 시험 감독
// Time Complexity O(n)
// int형 초과를 주의해야 하는 문제
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, a, b, c, i; // ai -> 각 방에 있는 응시자수, b - 총감독관 관리인원, c - 부감독관 관리인원
    unsigned long long int minNum;
    cin >> n;
    vector<int> peopleNum(n, 0);
    for (i = 0; i < n; i++)
        cin >> peopleNum[i];
    cin >> b >> c;

    // solving
    // 총감독관 수 구하기
    minNum = n;
    // 부감독관 수 구하기
    for (i = 0; i < n; i++) {
        peopleNum[i] -= b;
        if (peopleNum[i] > 0) {
            minNum += peopleNum[i] / c;
            if (peopleNum[i] % c > 0)
                minNum++;
        }
    }
    cout << minNum;
    return 0;
}
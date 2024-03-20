// Baekjoon No. 23658 Find the House - 220904 solved
// Time Complexity O(n)
/*
* map에 값들을 넣고, value값이 key에 존재하지 않으면 출력하는 알고리즘.
* 2021 icpc 기출문제
* 찬규가 말한 알고리즘 사용. 복기 필요
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, ans, st, ed;
    int i;
    char tmp;
    map<int, int> coords;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> st >> tmp >> ed;
        if (tmp == 'R')
            coords[st] = st + ed;
        else
            coords[st] = st - ed;
    }

    // solving
    for (map<int, int>::iterator itr = coords.begin(); itr != coords.end(); itr++) {
        // cout << itr->first << " : " << itr->second << '\n';
        if (coords.find(itr->second) == coords.end()) {
            ans = itr->second;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}
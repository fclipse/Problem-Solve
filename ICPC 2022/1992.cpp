// Baekjoon No. 1992 - 쿼드트리, 220921 solved
// Time Complexity O(n^2)
// #Quad Tree (Binary Tree), 분할 정복법

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string dfs(vector<string>& map, int n, int row, int col);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int i, j;
    cin >> n;
    vector<string> map(n);
    for (i = 0; i < n; i++) {
        cin >> map[i];
    }

    // solving
    cout << dfs(map, n / 2, n / 2, n / 2);
    
    return 0;
}
// 압축 결과 반환해주는 함수.
string dfs(vector<string>& map, int n, int row, int col) {
    if (n == 0) {
        return "0";
    }else if (n == 1) {
        string s1(1, map[row - 1][col - 1]);
        string s2(1, map[row - 1][col]);
        string s3(1, map[row][col - 1]);
        string s4(1, map[row][col]);
        if (s1 == s2 && s2 == s3 && s3 == s4 && (s1 == "0" || s1 == "1"))
            return s1;
        else
            return "(" + s1 + s2 + s3 + s4 + ")";
    }
    else {
        string s1 = dfs(map, n / 2, row - n / 2, col - n / 2);
        string s2 = dfs(map, n / 2, row - n / 2, col + n / 2);
        string s3 = dfs(map, n / 2, row + n / 2, col - n / 2);
        string s4 = dfs(map, n / 2, row + n / 2, col + n / 2);
        if (s1 == s2 && s2 == s3 && s3 == s4 && (s1 == "0" || s1 == "1"))
            return s1;
        else
            return "(" + s1 + s2 + s3 + s4 + ")";
    }
}
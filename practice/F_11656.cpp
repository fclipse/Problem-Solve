// Baekjoon No.
// Time Complexity
// #

#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

bool cmpStr(char c1, char c2);
int main() {
    fastIO;
    string s;
    int n, length, stIdx;
    int i;
    cin >> s;
    length = s.length();
    vector<map<int, char>> arr(length);
    for (i = 0; i < s.length(); i++) {
        arr.push_back({ i, s[i] });
    }
    sort(arr.begin(), arr.end(), cmpStr);
    for (i = 0; i < length; i++) {
        stIdx = arr[i].first();
        cout << s.substr() << "\n";
    }
        
    return 0;
}
bool cmpStr(map<int, char> c1, map<int, char> c2) {
    return *c1.begin() < *c2.begin();
}
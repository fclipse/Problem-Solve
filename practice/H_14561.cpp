// Baekjoon No.
// Time Complexity
// #

#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int palidrome(string n);
string convert(int n);

int main() {
    fastIO;
    int t, n;
    long long a;
    string res;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        res = "";
        cin >> a >> n;
        
        while (a) {
            res = convert(a % n) + res;   
            a /= n;
        }
        cout << palidrome(res) << "\n";
    }
    return 0;
}
int palidrome(string n) {
    int i = 0, length = n.length();
    for (i = 0; i <= length / 2; i++) {
        if (n[i] != n[length - i - 1]) return 0;
    }
    return 1;
}
string convert(int n) {
    if (n < 10) return to_string(n);
    string strs[6] = { "A", "B", "C", "D", "E", "F" };
    return strs[n - 10];
}
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n = 2, size, i, placeSum = 0, ans = 0;
    string strN;
    while (n < 1000000) {
        placeSum = 0;
        strN.clear();
        strN = to_string(n);
        size = strN.length();
        for (i = 0; i < size; i++) {
            placeSum += pow((strN[i] - '0'), 5);
        }
        if (placeSum == n) {
            cout << "ans : " << n << "\n";
            ans += n;
        }
        n++;
    }
    cout << ans;
    return 0;
}

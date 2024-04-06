#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);

using namespace std;

int gcd();

int main()
{
    fastio;
    // 입력 - 각 분수의 분자와 분모
    int t1, t2, b1, b2;
    cin >> t1 >> b1 >> t2 >> b2;

    // 분자와 분모를 각각 더한 후 최대공약수로 나눠준다.
    int top = t1 * b2 + t2 * b1;
    int bottom = b1 * b2;
    int g = gcd(top, bottom);
    cout << top / g << " " << bottom / g;

    return 0;
}

// 최대공약수 구하는 함수
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int gcd(int a, int b){
    if(b > a) swap(a, b);
    if(a % b == 0) return max(b, -b);
    return gcd(b, a % b);
}

int main() {
	fastio;
    cout << gcd(-8, 3);

	return 0;
}
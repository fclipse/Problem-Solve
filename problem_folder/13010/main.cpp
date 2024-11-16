#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 1000000
using namespace std;

// globals
long long dNumCache[MAX + 1] = {0};

// functions
long long dividerNum(long long n);
long long power(long long n, long long k);

int main() {
	fastio;
	long long n;
	cin >> n;
	// solving
	long long ans = -1;
	for (int i = 2; i * i <= n; i++){
		if(power(i, dividerNum(i)) == n){
			ans = i;
			break;
		}
	}
	// output
	cout << ans;

	return 0;
}

long long dividerNum(long long n){
	if(n <= MAX && dNumCache[n] > 0) return dNumCache[n];
	long long ans = 2;
	for (int i = 2; i * i <= n; i++){
		if(n % i == 0) ans += 2;
		if(i * i == n) ans -= 1;
	}
	if(n <= MAX){
		dNumCache[n] = ans;
	}
	return ans;
}

long long power(long long n, long long k){
	long long ans = 1;
	for (int i = 0; i < k; i++){
		ans *= n;
	}
	return ans;
}